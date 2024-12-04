class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int>mp;
        int n=s.length(),i=0;
        int ans=0;
        while(i<n){
            while(i<n && mp.find(s[i])==mp.end()){
                mp[s[i]]++;
                i++;
            } 
            mp.clear();
            ans++;
        }
        return ans;
    }
};