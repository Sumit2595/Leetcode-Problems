class Solution {
public:
    int solve(vector<int>nums,int n,vector<int>&dp){
        if(n<=0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int op1=nums[n-1]+solve(nums,n-2,dp);
        int op2=solve(nums,n-1,dp);
        return dp[n]=max(op1,op2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,n,dp);
    }
};