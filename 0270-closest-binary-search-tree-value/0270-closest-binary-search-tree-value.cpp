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
    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>pq;
    void solve(TreeNode* root, double target){
        if(!root)
            return;
        double diff=abs(root->val - target);
        pq.push({diff,root->val});
        solve(root->left,target);
        solve(root->right,target);
    }
    int closestValue(TreeNode* root, double target) {
        if(!root)
            return 0;
        solve(root,target);
        return pq.top().second;
    }
};