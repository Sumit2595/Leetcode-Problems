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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            vector<int>temp;
            for(int i=0;i<sz;i++){
                auto tp=q.front();q.pop();
                temp.push_back(tp->val);
                if(tp->left)
                    q.push(tp->left);
                if(tp->right)
                    q.push(tp->right);
            }
            if(level%2){
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);
            level++;
        }
        return ans;
    }
};