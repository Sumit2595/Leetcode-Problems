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
    int solve(TreeNode* root,int x){
        if(!root)
            return 0;
        int ans=0;
        if(root->val>=x){
            ans+=1+solve(root->left,root->val)+solve(root->right,root->val);
        } else {
            ans+=solve(root->left,x)+solve(root->right,x);
        }
        return ans;
    }
    int goodNodes(TreeNode* root) {
        return solve(root,INT_MIN);
    }
};