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
    int ans=INT_MIN;
    int solve(TreeNode* root){
        if(!root)
            return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        int curr=max({root->val,root->val+l,root->val+r});
        ans=max({ans,curr,root->val+l+r});
        return curr;
    }
    int maxPathSum(TreeNode* root) {
        if(!root->left && !root->right)
            return root->val;
        solve(root);
        return ans;
    }
};