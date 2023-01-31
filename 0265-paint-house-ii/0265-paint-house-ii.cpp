class Solution {
public:
    int dp[150][25];
    int k;
    int solve(vector<vector<int>>& costs,int row,int color){
        if(row>=costs.size())
            return 0;
        if(dp[row][color]!=-1)
            return dp[row][color];
        int mn=INT_MAX;
        int cost=costs[row][color];
        for(int i=0;i<k;i++){
            if(i==color)
                continue;
            int next=solve(costs,row+1,i);
            cost+=next;
            mn=min(mn,cost);
            cost-=next;
        }
        return dp[row][color]=mn;
    }
    int minCostII(vector<vector<int>>& costs) {
         int ans=INT_MAX;
        k=costs[0].size();
        for(int i=0;i<k;i++){
            memset(dp,-1,sizeof(dp));
            ans=min(ans,solve(costs,0,i)); 
        }
       return ans; 
    }
};