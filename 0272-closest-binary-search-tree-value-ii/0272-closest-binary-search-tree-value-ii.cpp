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
    #define pdi pair<double,int>
    priority_queue<pdi,vector<pdi>,greater<pdi>>pq;
    void solve(TreeNode* root,double target){
        if(!root)
            return;
        double diff=abs(root->val-target);
        pq.push({diff,root->val});
        solve(root->left,target);
        solve(root->right,target);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        solve(root,target);
        vector<int>vec;
        while(k--){
            cout<<pq.top().first<<" ";
            vec.push_back(pq.top().second);
            pq.pop();
        }
        return vec;
    }
};