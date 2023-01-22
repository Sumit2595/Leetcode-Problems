/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<int,TreeNode*>ans={INT_MAX,NULL};
    void solve(TreeNode* root,TreeNode* p){
        if(!root){
            return;
        }
        solve(root->left,p);
        if(root->val>p->val){
            if(ans.first>root->val){
                ans={root->val,root};
            }
        }
        solve(root->right,p);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        solve(root,p);
        return ans.second;
    }
};