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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>&arr,int l,int r){
        if(l>r)
              return NULL;
         int mid=(l+r)/2;
          TreeNode* root=new TreeNode(arr[mid]);
          root->left=solve(arr,l,mid-1);
          root->right=solve(arr,mid+1,r);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL || head->next==NULL){
               if(!head)
                 return NULL;
            TreeNode* root=new TreeNode(head->val);
                 return root;
         }
        vector<int>arr;
        ListNode* temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n=arr.size();
        return solve(arr,0,n-1);
        
    }
};