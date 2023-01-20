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
    int solve(TreeNode* root,int diff){
        if(!root)
            return 0;
        int l=0,r=0;
        if(root->left){
            if(root->val - root->left->val == diff){
                l=1+solve(root->left,diff);
            }
        }
        if(root->right){
            if(root->val - root->right->val == diff){
                r=1+solve(root->right,diff);
            }
        }
        return max(l,r);
    }
    int longestConsecutive(TreeNode* root) {
        if(!root)
            return 0;
        int len=solve(root,1) + solve(root,-1) + 1;
        return max({len,longestConsecutive(root->left),longestConsecutive(root->right)});
    }
};