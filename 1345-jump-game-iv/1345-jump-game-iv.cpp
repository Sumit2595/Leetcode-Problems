class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        int level=0;
        vector<int>vis(n,0);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int curr=q.front();q.pop();
                if(curr == n-1){
                    return level;
                }
                auto poss = mp[arr[curr]];
                poss.push_back(curr+1);
                poss.push_back(curr-1);
                for(auto x:poss){
                    if(x>=0 && x<=n-1 && !vis[x]){
                        q.push(x);
                        vis[x]=1;
                    }
                }
                mp.erase(arr[curr]);
            }
            level++;
        }
        return 0;
    }
};