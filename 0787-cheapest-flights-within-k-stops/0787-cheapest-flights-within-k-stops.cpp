class Solution {
public:
        int dp[100][102];
    int solve(int src,int dest,vector<pair<int,int>>adj[],int k)
    {   if(k<0)
          return INT_MAX;
         if(src==dest)
          return 0;
      if(dp[src][k]!=-1)
          return dp[src][k];    
      int ans=INT_MAX;
     for(int i=0;i<adj[src].size();i++)
      {  int a=solve(adj[src][i].first,dest,adj,k-1);
          ans=min(ans,(a==INT_MAX)?a:a+adj[src][i].second);       
      }
       return dp[src][k]=ans;         
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int numFlights = flights.size();
            vector<pair<int,int>>adj[n];//dest,price
       memset(dp,-1,sizeof(dp));
        for(int i = 0; i < numFlights; i++)
       {  int u=flights[i][0];
          int v=flights[i][1];
         int price=flights[i][2];
          adj[u].push_back({v,price});
       }
     vector<int>vis(n,false);
   int ans = solve(src, dst, adj, k + 1);
       return (ans==INT_MAX)?-1:ans;     
    }
};