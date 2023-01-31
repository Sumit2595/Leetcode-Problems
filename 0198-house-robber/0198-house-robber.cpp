class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums,int idx){
        if(idx>=nums.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int op1=nums[idx]+solve(nums,idx+2);
        int op2=solve(nums,idx+1);
        return dp[idx]=max(op1,op2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int dp1[n];
        dp1[0]=nums[0];
        dp1[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp1[i]=max(dp1[i-2]+nums[i],dp1[i-1]);
        }
        return dp1[n-1];
    }
};