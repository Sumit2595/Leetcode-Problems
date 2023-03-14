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
    int res=0;
    void solve(int curr,TreeNode *root)
    {  if(root->left==NULL && root->right==NULL)
      {   res+=curr;   
        return;
       }
    if(root->left) 
     solve(root->left->val+10*curr,root->left);
    if(root->right) 
     solve(root->right->val+10*curr,root->right);
    }
    int sumNumbers(TreeNode* root) {
      solve(root->val,root);
     return res;
    }
};