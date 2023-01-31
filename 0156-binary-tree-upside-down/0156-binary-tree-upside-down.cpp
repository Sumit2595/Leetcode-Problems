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
    TreeNode* newRoot=NULL;
    TreeNode* solve(TreeNode* root,TreeNode* prev){
        if(!root)
            return root;
        solve(root->left,root);
        root->right=prev;
        root->left=!prev ? NULL : prev->right;
        if(!newRoot){
            newRoot=root;
        }
        return root;
    }
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
       solve(root,NULL);
        return newRoot;
    }
};