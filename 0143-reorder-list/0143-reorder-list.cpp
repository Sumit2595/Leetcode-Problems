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
    void reorderList(ListNode* head) {
        if(head->next == NULL || head->next->next==NULL)
            return;
        int sz=0;
        stack<ListNode*>st;
        ListNode* temp=head;
        while(temp){
            sz++;
            st.push(temp);
            temp=temp->next;
        }
        int rem=sz/2 + sz%2;
        ListNode* prev=head;
        for(int i=0;i<rem;i++){
            ListNode* t=st.top();
            st.pop();
            t->next=prev->next;
            prev->next=t;
            prev=prev->next->next;
        }
      prev->next=NULL;
    }
};