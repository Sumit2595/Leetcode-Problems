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
    #define ll long long
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<ll>temp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            ll sum=0;
            for(int i=0;i<sz;i++){
                auto tp=q.front();q.pop();
                sum+=tp->val;
                if(tp->left)
                    q.push(tp->left);
                if(tp->right)
                    q.push(tp->right);
            }
            temp.push_back(sum);
        }
        if(temp.size()<k){
            return -1;
        }
        int sz=temp.size();
        sort(temp.rbegin(),temp.rend());
        return temp[k-1];
    }
};