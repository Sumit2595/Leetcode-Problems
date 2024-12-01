class Solution {
public:
    vector<vector<int>>dp;
    bool solve(vector<int>& nums,int sum,int n){
        if(n<=0)
            return false;
        if(sum==0)
            return true;
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        bool op1=false,op2=false;
        if(nums[n-1]<=sum){
            op1=solve(nums,sum-nums[n-1],n-1);
            op2=solve(nums,sum,n-1);
        } else {
            op2=solve(nums,sum,n-1);
        }
        return dp[n][sum]=op1 || op2;   
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(auto num:nums)
            sum+=num;
        if(sum%2)
            return false;
        sum=sum/2;
        dp=vector<vector<int>>(n+10,vector<int>(sum+10,-1)); 
        return solve(nums,sum,n);
    }
};