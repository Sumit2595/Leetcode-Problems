class Solution {
public:
    int solve(int k,int n,vector<vector<int>>&dp){
        if(k==1 || n<=1)
            return n;
        int l=1,r=n,mn=INT_MAX;
        if(dp[n][k]!=-1)
            return dp[n][k];
        while(l<=r){
            int mid=(l+r)/2;
            int egg_break=solve(k-1,mid-1,dp);
            int egg_not_break=solve(k,n-mid,dp);
            if(egg_break<egg_not_break)
                l=mid+1;
            else
                r=mid-1;
            int temp=1+max(egg_break,egg_not_break);
            mn=min(mn,temp);
        }
        return dp[n][k]=mn;
    }
    int superEggDrop(int k, int n) {
         vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(k,n,dp);
    }
};