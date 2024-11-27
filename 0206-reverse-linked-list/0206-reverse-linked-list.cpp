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
    ListNode* h1;
    void solve(ListNode* first,ListNode* second){
        if(!second->next){
            h1=second;
            second->next=first;
            return;
        }
        solve(second,second->next);
        second->next=first; 
    }
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
       solve(NULL,head);
       return h1;    
    }
};