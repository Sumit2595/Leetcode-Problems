class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int r=0,l=0,ans=0;
        unordered_map<char,int>mp;
        while(r<n){
            mp[s[r]]++;
            while(l<r && mp[s[r]] > 1){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};