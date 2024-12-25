class Solution {
public:
    vector<int>dp;
    int solve(vector<int>& nums,int idx,int n){
        if(idx >= n)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int option1=nums[idx]+solve(nums,idx+2,n);
        int option2=solve(nums,idx+1,n);
        return dp[idx]=max(option1,option2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,-1);
        return solve(nums,0,n);
    }
};