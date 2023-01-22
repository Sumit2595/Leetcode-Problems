class Solution {
public:
    vector<int>vis;
    bool isCyclic(vector<int>graph[],int child,int parent){
        vis[child]=1;
        for(auto u:graph[child]){
            if(!vis[u]){
                if(isCyclic(graph,u,child)){
                    return true;
                }
            } else {
                if(u != parent)
                    return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int>graph[n];
        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
       vis=vector<int>(n,0);
        bool cycle=isCyclic(graph,0,-1);
        for(auto x:vis){
            if(x == 0)
                return false;
        }
        return !cycle;
    }
};