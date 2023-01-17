class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>& coins, int n,int amount){
      if(n<0 || amount<0)
       return INT_MAX/2; 
      if(amount == 0)
       return 0;
      if(n==0)
       return INT_MAX/2;
      if(dp[n][amount]!=-1)
       return dp[n][amount]; 
      int op1=min(1+solve(coins,n,amount-coins[n-1]),solve(coins,n-1,amount));
      int op2=solve(coins,n-1,amount);
      return dp[n][amount]=min(op1,op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp=vector<vector<int>>(coins.size()+10,vector<int>(amount+10,-1));
        int ans=solve(coins,n,amount);
        return ans>=INT_MAX/2?-1:ans;
    }
};