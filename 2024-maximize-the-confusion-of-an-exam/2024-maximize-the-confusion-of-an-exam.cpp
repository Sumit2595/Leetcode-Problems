class Solution {
public:
    int maxConsecutiveAnswers(string str, int k) {
        int n=str.length();
        if(n <= k){
            return n;
        }
        unordered_map<char,int>mp;
        int ans=1;
        for(int i=0;i<k;i++){
            mp[str[i]]++;
        }
        int left=0,right=k;
        for(;right<n;right++){
            mp[str[right]]++;
            while(min(mp['T'],mp['F']) > k){
                mp[str[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};