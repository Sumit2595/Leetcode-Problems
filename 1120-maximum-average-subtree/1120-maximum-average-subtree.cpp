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
    #define pp pair<double,int>
    #define ll long long
    double ans=-1.0;
    pp solve(TreeNode* root){
        if(!root){
            return {0,0};
        }
        pp l=solve(root->left);
        pp r=solve(root->right);
        ll sum=root->val+l.first+r.first;
        ll total=1+l.second+r.second;
        double average = sum/(double)total;
        ans=max(ans,average);
        return {sum,total};
    }
    double maximumAverageSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};