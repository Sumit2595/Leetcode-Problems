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
    ListNode* root;
    void solve(ListNode* temp,ListNode* node)
    {  if(temp->next==NULL){
          root->next=NULL;
             delete temp;
            return;   
        }
       temp->val=node->val;
        root=temp;
       solve(temp->next,node->next);
      
            
    }
    void deleteNode(ListNode* node) {
        ListNode* temp=node;
        solve(temp,node->next);
    }
};