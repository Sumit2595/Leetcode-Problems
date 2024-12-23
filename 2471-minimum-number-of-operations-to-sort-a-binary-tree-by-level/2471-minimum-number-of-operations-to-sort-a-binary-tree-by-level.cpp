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
    int minSwaps(vector<int>values){
          int min_swaps=0;

        //Store K->Value...V->Actual_Idx Ordered Map
        map<int,int> sorted_map;
        int n=values.size();
        for(int j=0;j<n;++j)
            sorted_map[values[j]]=j;

        //Sort the array to know the expected index
        sort(values.begin(),values.end());

        vector<bool> visited(n,false);//This marks already processed indices
        int iteration=0;    //Row number of Map
        for(auto& [val,idx]: sorted_map){
            if(visited[idx]){//Don't process if already done
                iteration++;
                continue;
            }    

            visited[idx]=true;
            int len=1;//Find length of cycle
            while(idx!=iteration){
                idx = sorted_map[values[idx]];
                visited[idx]=true;
                len++;
            }
            min_swaps += len-1;//Add no of swaps for the current loop
            iteration++;
        }
        return min_swaps; 
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            vector<int>temp;
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();q.pop();
                temp.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans+=minSwaps(temp);
        }
        return ans;
    }
};