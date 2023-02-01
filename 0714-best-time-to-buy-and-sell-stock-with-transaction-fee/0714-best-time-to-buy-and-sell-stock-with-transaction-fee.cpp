class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>& prices, int fee,int idx,int brought){
        if(idx>=prices.size())
            return 0;
        if(dp[idx][brought]!=-1){
            return dp[idx][brought];
        }
        int profit=0;
        if(brought){
            int sell= prices[idx]+solve(prices,fee,idx+1,0)-fee;
            int notSell= solve(prices,fee,idx+1,1);   
            profit=max({profit,sell,notSell});
        } else {
            int buy=-prices[idx]+solve(prices,fee,idx+1,1);
            int notBuy=solve(prices,fee,idx+1,0);
            profit=max({profit,buy,notBuy});
        }
        return dp[idx][brought]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        dp=vector<vector<int>>(n+1,vector<int>(2,-1));
        return solve(prices,fee,0,0);
    }
};