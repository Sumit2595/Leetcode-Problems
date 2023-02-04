class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int ans=0,maxCount=0;
        unordered_map<char,int>mp;
        int l=0,r=0;
        while(r<n){
            mp[s[r]]++;
            maxCount=max(maxCount,mp[s[r]]);
            while(r-l+1 - maxCount > k){
                mp[s[l]]--;
                l++;
                maxCount=max(maxCount,mp[s[r]]);
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};