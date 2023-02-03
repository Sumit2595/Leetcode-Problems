class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char,int>mp;
        int n=s.length();
        int right=0,left=0,ans=0;
        while(right<n){
            mp[s[right]]++;
            while(left<=right && mp.size() > k){
                mp[s[left]]--;
                if(mp[s[left]] == 0){
                    mp.erase(s[left]);
                }
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};