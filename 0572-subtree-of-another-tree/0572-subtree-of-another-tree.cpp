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
    bool solve(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot)
          return true;
        if(!root || !subRoot || root->val != subRoot->val){
            return false;
        }
        bool l=solve(root->left,subRoot->left);
        bool r=solve(root->right,subRoot->right);
        return l && r;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot)
            return false;
        if(solve(root,subRoot))
            return true;
        bool l=isSubtree(root->left,subRoot);
        bool r=isSubtree(root->right,subRoot);
        return l||r;
    }
};