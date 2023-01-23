class Solution {
public:
    int dp[10001];
    int solve(vector<int>& nums,int curr,int dest){
        if(curr>=dest)
            return 0;
        if(dp[curr]!=-1)
            return dp[curr];
        int steps=INT_MAX-1;
        for(int i=1;i<=nums[curr];i++){
            steps=min(steps,1+solve(nums,curr+i,dest));
        }
        return dp[curr]=steps;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,n-1);
    }
};