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
    TreeNode* solve(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root)
            return NULL;
        if(root->val == p->val || root->val == q->val)
            return root;
        auto left=solve(root->left,p,q);
        auto right=solve(root->right,p,q);
        if(left!=NULL && right!=NULL)
            return root;
        if(left != NULL)
            return left;
        return right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        if(!root)
            return root;
        if(nodes.size() == 1)
            return nodes[0];
        auto temporary=solve(root,nodes[0],nodes[1]);
        for(int i=2;i<nodes.size();i++){
            temporary=solve(root,nodes[i],temporary);
        }
        return temporary;
    }
};