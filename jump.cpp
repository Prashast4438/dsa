class Solution {
public:
    // 'maxReach' will track the farthest index we can reach so far
    int maxReach = 0;

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        // Iterate through each position
        for (int i = 0; i < n; ++i) {
            // If current index is beyond our max reachable, we can't proceed
            if (i > maxReach) {
                return false;
            }
            
            // Update maxReach: from this position, we can jump at most nums[i] steps
            maxReach = max(maxReach, i + nums[i]);
        }
        
        // If we've iterated through all indices without failing, we can reach the end
        return true;
    }
};
