class Solution {
public:
    #define mm INT_MAX/2
    vector<int>dp;
    int solve(vector<int>& days, vector<int>& costs,int x,int n){
        if(x>=n){
            return 0;
        }
        if(dp[x]!=-1){
            return dp[x];
        }
        int op1=costs[0]+solve(days,costs,x+1,n);
        int k=x;
        int op2=mm,op3=mm;
        for(;k<n;k++){
            if(days[k]>=days[x]+7)
                break;
        }
        op2=costs[1]+solve(days,costs,k,n);
        k=x;
        for(;k<n;k++){
            if(days[k]>=days[x]+30)
                break;
        }
        op3=costs[2]+solve(days,costs,k,n);
        return dp[x]=min({op1,op2,op3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        dp.resize(n+1,-1);
        return solve(days,costs,0,n);
    }
};