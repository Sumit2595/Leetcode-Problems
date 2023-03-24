class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n),back(n);
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            back[x[1]].push_back(x[0]);
        }
        queue<int>q;
        vector<int>vis(n,0);
        q.push(0);
        int count=0;
        while(!q.empty()){
            int curr=q.front();q.pop();
            vis[curr]=1;
            for(auto x:adj[curr]){
                if(!vis[x]){
                    count++;
                    q.push(x);
                }
            }
            for(auto x:back[curr]){
                if(!vis[x]){
                    q.push(x);
                }
            }
        }
        return count;
    }
};