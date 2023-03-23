class Solution {
public:
    void dfs(vector<vector<int>> &graph,int parent,vector<bool>&visited){
        visited[parent]=true;
        for(auto child:graph[parent]){
            if(!visited[child]){
                dfs(graph,child,visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n>connections.size()+1)
            return -1;
        
        vector<vector<int>> graph(n);
        for(auto con : connections){
            graph[con[0]].push_back(con[1]);
            graph[con[1]].push_back(con[0]);
        }
        vector<bool> visited(n ,false);
        int component=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                component++;
                dfs(graph,i,visited);
            }
        }
        return component-1;
    }
};