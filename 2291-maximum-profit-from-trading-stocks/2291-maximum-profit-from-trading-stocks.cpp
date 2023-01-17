class Solution {
public:
    vector<vector<int>>dp;
    int getMaxProfit(vector<int>& present, vector<int>& future, int idx,int budget){
        if(idx>=present.size())
            return 0;
        if(budget<0)
            return 0;
        if(dp[idx][budget]!=-1)
            return dp[idx][budget];
        int profit=0;
        if(budget>=present[idx]){
            profit=max(profit,future[idx]-present[idx]+getMaxProfit(present,future,idx+1,budget-                                                present[idx]));
            profit=max(profit,getMaxProfit(present,future,idx+1,budget));
        } else{
            profit=max(profit,getMaxProfit(present,future,idx+1,budget));
        }
        return dp[idx][budget]=profit;
    }
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n=present.size();
        dp=vector<vector<int>>(n+1,vector<int>(budget+1,-1));
        return getMaxProfit(present,future,0,budget);
    }
};