class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int i=0,j=0;
        unordered_map<int,int>mp;
        int ans=0;
        while(j<n){
            mp[s[j]]++;
            while(i<j && mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }

                ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};