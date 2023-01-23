class Solution {
public:
    string getKey(int a,int b){
        return to_string(a) + "$" + to_string(b);
    }
    int findJudge(int n, vector<vector<int>>& trust) {
       vector<int>graph[n+1];
        unordered_map<string,int>mp;
        for(auto t:trust){
            string key=getKey(t[0], t[1]);
            graph[t[0]].push_back(t[1]);
            mp[key] = 1;
        }
        int judge=INT_MAX;
        for(int i=1;i<=n;i++){
            if(graph[i].size() == 0){
                if(judge!=INT_MAX)
                return -1;
                else{
                    judge=i;
                }
            }
        }
        if(judge == INT_MAX){
            return -1;
        }
        for(int i=1;i<=n;i++){
            if(judge == i) continue;
            string key=getKey(i,judge);
            if(mp[key] == 0){
                return -1;
            }
        }
        return judge;
    }
};