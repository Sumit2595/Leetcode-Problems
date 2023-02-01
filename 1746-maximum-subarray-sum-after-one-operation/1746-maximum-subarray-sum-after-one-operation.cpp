class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n=nums.size();
        int dp[n][2];
        dp[0][0]=nums[0];
        dp[0][1]=nums[0]*nums[0];
        int ans=max(dp[0][0],dp[0][1]);
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0]+nums[i],nums[i]);
            dp[i][1]=max({dp[i-1][0]+nums[i]*nums[i],dp[i-1][1]+nums[i],nums[i]*nums[i]});
            ans=max(dp[i][1],ans);
        }
        return ans;
    }
};