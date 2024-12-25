class Solution {
public:
    vector<int>dp;
    int solve(vector<int>& cost,int idx,int n){
        if(idx >= n)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int option1=cost[idx]+min(solve(cost,idx+1,n),solve(cost,idx+2,n));
        return dp[idx]=option1;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.resize(n+1,-1);
        return min(solve(cost,0,n),solve(cost,1,n));
    }
};