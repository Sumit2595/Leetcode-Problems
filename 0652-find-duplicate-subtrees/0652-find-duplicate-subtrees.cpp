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
    unordered_map<string,vector<TreeNode*>>mp;
    string solve(TreeNode* root){
        if(!root){
            return "NULL";
        }
        string key=to_string(root->val);
        string l=solve(root->left);
        string r=solve(root->right);
        key+="#"+l+"#"+r;
        mp[key].push_back(root);
        return key;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        vector<TreeNode*>ans;
        for(auto x:mp){
            if(x.second.size() >=2 )
                ans.push_back(x.second[0]);
        }
        return ans;
    }
};