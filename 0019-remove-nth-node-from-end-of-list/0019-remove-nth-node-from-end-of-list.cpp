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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total=0;
        ListNode* t=head;
        while(t!=NULL)
        {  total++;
            t=t->next;  
        }
        if(total==n)
        { ListNode* prev=head;
            head=head->next;
          prev->next=NULL;
         return head;
        }
       int last=total-n+1;
        t=head;
        ListNode* prev=NULL;
        for(int i=0;i<last-1;i++)
        {   prev=t; 
            t=t->next;
        }
        prev->next=t->next;
        t->next=NULL;
         
       return head; 
    }
};