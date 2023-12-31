class Solution {
public:
    int maxLengthBetweenEqualCharacters(string str) {
        unordered_map<char,vector<int>>mp;
        int i=0;
        for(auto s:str){
            mp[s].push_back(i);
            i++;
        }
        int ans=-1;
        for(auto it:mp){
            vector<int>v=it.second;
            int n=v.size();
            if(n>1){
                ans=max(ans,(v[n-1]-v[0]-1));
            }
        }
        return ans;
    }
};