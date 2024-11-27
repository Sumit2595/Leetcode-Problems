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
    int getHeight(TreeNode* root){
        if(!root)
            return 0;
        int left=getHeight(root->left);
        int right = getHeight(root->right);
        int height=1+max(left,right);
        return height;
    }
    bool check(TreeNode* root){
        if(!root)
            return true;
        auto left=getHeight(root->left);
        auto right=getHeight(root->right);
        return (abs(left-right) <= 1) && check(root->left) && check(root->right);
         
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        return check(root);
    }
};