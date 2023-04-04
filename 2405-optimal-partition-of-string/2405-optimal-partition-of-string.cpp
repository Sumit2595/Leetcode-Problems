class Solution {
public:
    int partitionString(string s) {
        int ans=1;
        unordered_map<char,int>mp;
        int n=s.length();
        int i=0;
        while(i<n){
            if(mp.find(s[i])!=mp.end()){
              ans++;
              mp.clear();
            } 
            mp[s[i]]++;
            i++;
        }
        return ans;
    }
};