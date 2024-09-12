/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 ListNode *reverse(ListNode*node)
 {
    ListNode *prev=NULL;
    ListNode *front=node;
    while(node!=NULL)
    {
      front=node->next;
      node->next=prev;
      prev=node;
      node=front;

    }
    return prev;
 }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode*fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
    ListNode *newHead=reverse(slow);
        
      ListNode *  temp1=head;
       ListNode * temp2=newHead;
        while(temp2!=NULL)
        {
           if(temp1->val!=temp2->val)
           {
            reverse(newHead);
            return false;

           }
           temp1=temp1->next;
           temp2=temp2->next;
        }
        
        reverse(newHead);
        return true;
    }
};
2nd approach



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 ListNode *reverse(ListNode*node)
 {
    ListNode *prev=NULL;
    ListNode *front=node;
    while(node!=NULL)
    {
      front=node->next;
      node->next=prev;
      prev=node;
      node=front;

    }
    return prev;
 }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode*fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
    ListNode *newHead=reverse(slow->next);
        
      ListNode *  temp1=head;
       ListNode * temp2=newHead;
        while(temp2!=NULL)
        {
           if(temp1->val!=temp2->val)
           {
            reverse(newHead);
            return false;

           }
           temp1=temp1->next;
           temp2=temp2->next;
        }
        
        reverse(newHead);
        return true;
    }
};
