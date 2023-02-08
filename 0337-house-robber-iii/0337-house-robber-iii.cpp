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
    unordered_map<TreeNode*,int>mp;
    int solve(TreeNode* root){
        if(!root)
            return 0;
        if(mp.find(root)!=mp.end()){
            return mp[root];
        }
        int op1=root->val;
        int op2=0;
        if(root->left){
            op1+=solve(root->left->left)+solve(root->left->right);
        }
        if(root->right){
            op1+=solve(root->right->left)+solve(root->right->right);
        }
        op2=solve(root->left)+solve(root->right);
        return mp[root]=max(op1,op2);
    }
    int rob(TreeNode* root) {
        return solve(root);
    }
};