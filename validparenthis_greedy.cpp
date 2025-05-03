class Solution {
public:
    // Recursive helper function to check if the string can be valid
    // index: current character position in the string
    // count: current balance of open parentheses
    bool helper(string s, int index, int count) {
        // If at any point we have more ')' than '(', it's invalid
        if (count < 0) {
            return false;
        }

        // If we've reached the end of the string,
        // check if all open parentheses are matched
        if (index == s.size()) {
            return (count == 0);
        }

        // If the current character is '(', increment the count
        if (s[index] == '(') {
            return helper(s, index + 1, count + 1);
        }

        // If the current character is ')', decrement the count
        if (s[index] == ')') {
            return helper(s, index + 1, count - 1);
        }

        // If the current character is '*', try all 3 possibilities:
        // 1. Treat '*' as '('  → increment count
        // 2. Treat '*' as ')'  → decrement count
        // 3. Treat '*' as empty → leave count unchanged
        return helper(s, index + 1, count + 1) ||   // '*' as '('
               helper(s, index + 1, count - 1) ||   // '*' as ')'
               helper(s, index + 1, count);         // '*' as empty
    }

    // Main function to check if a string is a valid parenthesis string
    bool checkValidString(string s) {
        return helper(s, 0, 0); // Start from index 0 with count 0
    }
};

class Solution {
public:
    bool checkValidString(string s) {
        int min = 0;    // "low": minimum possible unmatched '('
        int max = 0;    // "high": maximum possible unmatched '('

        // Iterate through each character
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                // An '(' increases both low and high by 1
                min = min + 1;
                max = max + 1;
            }
            else if (s[i] == ')') {
                // A ')' decreases both low and high by 1
                min = min - 1;
                max = max - 1;
            }
            else {
                // A '*' could be ')': min-1, or '(' : max+1
                min = min - 1;
                max = max + 1;
            }

            // If max < 0, too many ')' even if all '*' were '('
            if (max < 0) {
                return false;
            }
            
            //  (min) can't go below 0: treat extra '*' as empty
            if (min < 0) {
                min = 0;
            }
        }

        // If min  is zero, there's some assignment of '*' to balance all '('
        return (min == 0);
    }
};
