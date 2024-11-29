class Solution {
public:
    vector<int>vis;
    vector<int>dfsVis;
    bool checkCycle(vector<int>graph[],int parent){
        vis[parent]=1;
        dfsVis[parent]=1;
        for(auto child:graph[parent]){
            if(!vis[child]){
                if(checkCycle(graph,child))
                  return true;
            } else if(dfsVis[child]) {
                return true;
            }
        }
        dfsVis[parent]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
       vis=vector<int>(numCourses,0);
        dfsVis=vector<int>(numCourses,0);
        vector<int>graph[numCourses];
        int n=pre.size();
        for(int i=0;i<n;i++){
            graph[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(checkCycle(graph,i))
                  return false;
            }
        }
        return true; 
    }
};