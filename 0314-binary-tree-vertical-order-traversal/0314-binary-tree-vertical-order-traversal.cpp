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
    #define pp pair<int,TreeNode*> //{dist,root address}
    #define ppp pair<int,vector<int>>
    unordered_map<int,vector<int>>mp;
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)
            return {};
        queue<pp>q;
        q.push({0,root});
        while(!q.empty()){
         int sz=q.size();
            for(int i=0;i<sz;i++){
                auto tp=q.front();q.pop();
                auto node = tp.second;
                int dist=tp.first;
                mp[dist].push_back(node->val);
                if(node->left){
                    q.push({dist-1,node->left});
                }
                if(node->right){
                    q.push({dist+1,node->right});
                }
            }  
        }
        vector<ppp>vec;
        for(auto x:mp){
            vec.push_back({x.first,x.second});
        }
        sort(vec.begin(),vec.end());
        for(auto x:vec){
            ans.push_back(x.second);
        }
        return ans;
    }
};