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
     int total=0;
public:
    ListNode* temp;
    Solution(ListNode* head) {
        temp=head;
        while(temp!=NULL){
            total++;
            temp=temp->next;
        }
        temp=head;
    }
    
    int getRandom() {
        int pos=rand()%total+1;
        ListNode* trav=temp;
        while(trav!=NULL && pos!=1){
            trav=trav->next;
            pos--;
        }
        return trav->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */