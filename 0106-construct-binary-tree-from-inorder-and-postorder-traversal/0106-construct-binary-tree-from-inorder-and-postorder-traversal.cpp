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
    unordered_map<int, int> dict;
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int &idx,int low,int high){ 
        if(low>high){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[idx]);
        int i=dict[postorder[idx--]];
        root->right=solve(inorder,postorder,idx,i+1,high);
        root->left=solve(inorder,postorder,idx,low,i-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int idx=n-1;
        for(int i = 0; i < n; i++){
            dict[inorder[i]] = i;
        }
        return solve(inorder,postorder,idx,0,n-1);
    }
};