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
    bool check(TreeNode* root,TreeNode* p){
        if(!root)
            return false;
        if(root->val == p->val)
            return true;
        bool l = check(root->left,p);
        bool r = check(root->right,p);
        return l || r;
    }
    TreeNode* solve(TreeNode* root,TreeNode* p, TreeNode* q){
        if(!root)
            return NULL;
        if(root->val == p->val || root->val == q->val)
            return root;
        TreeNode* l=solve(root->left,p,q);
        TreeNode* r=solve(root->right,p,q);
        if(l != NULL && r != NULL)
            return root;
        if(l == NULL)
            return r;
        return l;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(!check(root,p) || !check(root,q))
            return NULL;
            
        return solve(root,p,q);
    }
};