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
    unordered_map<int,vector<int>>mp;
    void solve(TreeNode* root,int level){
        if(!root)
            return;
        mp[level].push_back(root->val);
        solve(root->left,level+1);
        solve(root->right,level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        solve(root,0);
        int h=mp.size();
        vector<vector<int>>ans(h);
        for(int i=0;i<h;i++){
            if(i%2 == 0){
                ans[i]=mp[i];
            }else {
            auto temp=mp[i];
                reverse(temp.begin(),temp.end());
            ans[i]=temp;
            }
        }
        return ans;
    }
};