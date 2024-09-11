time complexity-o(n)
space complexity-o(1)
approach 
ideal- modied slow and fast pointer;
1- hashing



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*temp=head;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
            {
               slow=head;
               while(slow!=fast)
               {
                slow=slow->next;
                fast=fast->next;
               }
               return slow;
            }
        }
        return NULL;
        
    }
};
