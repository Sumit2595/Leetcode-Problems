class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>& prices,int idx,int brought){
        if(idx>=prices.size())
            return 0;
        if(dp[idx][brought]!=-1){
            return dp[idx][brought];
        }
        int profit=0;
        if(brought){
            int sell= prices[idx]+solve(prices,idx+2,0);
            int notSell= solve(prices,idx+1,1);   
            profit=max({profit,sell,notSell});
        } else {
            int buy=-prices[idx]+solve(prices,idx+1,1);
            int notBuy=solve(prices,idx+1,0);
            profit=max({profit,buy,notBuy});
        }
        return dp[idx][brought]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp=vector<vector<int>>(n+1,vector<int>(2,-1));
     return solve(prices,0,0);   
    }
};