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
    ListNode* slow;
        ListNode* fast;
    bool check(ListNode* head)
    {   slow=head;
        fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {   slow=slow->next;
            fast=fast->next->next;
          if(slow==fast)
            return true;            
        }
       return false; 
    }
    ListNode *detectCycle(ListNode *head) {
       if(check(head)) 
       {  fast=head;
         while(fast!=slow)
         { fast=fast->next;  
           slow=slow->next;   
         }
         return fast;  
       }
       return NULL; 
    }
};