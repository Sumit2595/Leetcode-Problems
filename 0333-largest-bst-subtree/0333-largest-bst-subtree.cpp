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
    vector<int> solve(TreeNode* root){
        if(!root){
            return {INT_MAX,INT_MIN,0};
        }
        auto l=solve(root->left);
        auto r=solve(root->right);
        if(root->val>l[1] && root->val<r[0]){
            return {min(root->val,l[0]),max(root->val,r[1]),l[2]+r[2]+1};
        } else {
           return {INT_MIN,INT_MAX,max(l[2],r[2])};
        }  
    }
    int largestBSTSubtree(TreeNode* root) {
        // res[0] ---> min
        // res[1] ---> max
        // res[2] ---> bst value
        vector<int>res=solve(root);
        return res[2];
    }
};