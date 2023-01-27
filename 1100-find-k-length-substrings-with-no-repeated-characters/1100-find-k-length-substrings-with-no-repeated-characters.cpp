class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int ans=0;
        unordered_map<char,int>mp;
        int n=s.length();
        if(k>n)
            return ans;
        int start=0,end=0;
        while(end<n){
           char ch=s[end];
           mp[ch]++;
           if(mp[ch] > 1){
               while(start<=end && mp[s[start]] > 1){
                   mp[s[start]]--;
                   if(mp[s[start]] == 0){
                       mp.erase(s[start]);
                   }
                   start++;
               }
           }
            while(end - start >= k){
                   mp[s[start]]--;
                   if(mp[s[start]] == 0){
                       mp.erase(s[start]);
                   }
              start++;
            }
           if(mp.size() == k){
               ans++;
           }
           end++;
        }
        return ans;
    }
};