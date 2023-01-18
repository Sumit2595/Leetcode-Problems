class Solution {
public:
    int dp[1000];
    int solve(string s,int idx,int n){
        if(idx>n)
            return 0;
        if(idx==n)
            return 1;
        if(dp[idx]!=-1)
            return dp[idx];
        int ans=0,op1=0,op2=0;
        int val=s[idx]-'0';
        if(val>=1)
            op1=solve(s,idx+1,n);
        if(idx<n-1){
            val=10*val+(s[idx+1]-'0');
        }
        if(10<=val && val<=26)
            op2=solve(s,idx+2,n);
        return dp[idx]=op1+op2;
    }
    int numDecodings(string s) {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        return solve(s,0,n);
    }
};