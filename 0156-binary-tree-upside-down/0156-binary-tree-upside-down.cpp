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
    TreeNode* dfs(TreeNode* root,TreeNode* parent){
        if(!root){
            return parent;
        }
        TreeNode* res=dfs(root->left,root);
        if(parent){
            root->right=parent;
            root->left=parent->right;
        } else {
            root->left=NULL;
            root->right=NULL;
        }
        return res;
    }
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        return dfs(root,NULL);
    }
};