class Solution {
public:
    #define pp pair<int,int>
    #define MAX INT_MAX/2
    vector<int>vis;
    vector<int>ans;
    //0 is for Red and 1 is for blue
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pp>graph[n];
        for(auto x:redEdges){
            graph[x[0]].push_back({x[1],0});
        }
        for(auto x:blueEdges){
            graph[x[0]].push_back({x[1],1});
        }
        vector<int>lastRed(n,MAX),lastBlue(n,MAX);
        lastRed[0]=0,lastBlue[0]=0;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int node=q.front();q.pop();
            for (auto& [child, color] : graph[node]) {
                if(color == 0 && lastBlue[node] + 1 < lastRed[child]){
                    lastRed[child] = lastBlue[node] + 1;
                    q.push(child);
                } else if(color == 1 && lastRed[node] + 1 < lastBlue[child]){
                    lastBlue[child] = lastRed[node] + 1;
                    q.push(child);
                }              
            }  
        }
        vector<int> ans;
		for(int i = 0; i < n; i++) {
			int temp = min(lastRed[i], lastBlue[i]);
			ans.push_back((temp >= MAX) ? -1 : temp);
		}
		return ans;
    }
};