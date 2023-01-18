class Solution {
public:
    int solve(int e,int f,vector<vector<int>>&dp){
       if(e==1 || f<=1)
           return f;
        if(dp[f][e]!=-1)
            return dp[f][e];
        int l=1,r=f;
        int mn=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            int egg_break=solve(e-1,mid-1,dp);
            int egg_not_break=solve(e,f-mid,dp);
            if(egg_break<egg_not_break)
                l=mid+1;
            else
                r=mid-1;
            int temp=1+max(egg_break,egg_not_break);
            mn=min(mn,temp);
        }
        return dp[f][e]=mn;
    }
    int twoEggDrop(int n) {
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return solve(2,n,dp);
    }
};