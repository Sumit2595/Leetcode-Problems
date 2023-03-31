class Solution {
public:
    int maxA(int n) {
        if(n<=6)
         return n;
         vector<int>dp(n+1);
         for(int i=1;i<=6;i++){
             dp[i]=i;
         }
         for(int i=7;i<=n;i++){
             int maxim=i;
             for(int j=i-3;j>=1;j--) {
                 int curr=dp[j]*(i-j-1);
                 maxim=max(maxim,curr);
             }
             dp[i]=maxim;
         }
         return dp[n];
    }
};