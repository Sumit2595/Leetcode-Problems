#define ll long long
class Solution {
public:
    const static int m = 1000000007;
    int numberOfWays(int n) {
        vector<int>dp(n/2+1);
        dp[0]=1;
        for(int i=1;i<=n/2;i++){
            for(int j=0;j<i;j++){
                dp[i]= (dp[i]+((ll)dp[j] * (ll)dp[i-j-1])%m)%m;
            }
        }
        return dp[n/2];
    }
};