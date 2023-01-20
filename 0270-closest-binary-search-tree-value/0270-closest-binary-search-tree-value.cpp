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
    int ans;
    void solve(TreeNode* root, double target,double currDiff){
        if(!root){
            return;
        }
        double diff=root->val-target;
        if(diff < 0){
            if(abs(diff) < currDiff){
                currDiff=abs(diff);
                ans=root->val;
            }
            solve(root->right,target,currDiff);
        } else {
            if(abs(diff) < currDiff){
                currDiff=abs(diff);
                ans=root->val;
            }
            solve(root->left,target,currDiff);
        }
    }
    int closestValue(TreeNode* root, double target) {
        solve(root,target,LONG_MAX);
        return ans;
    }
};