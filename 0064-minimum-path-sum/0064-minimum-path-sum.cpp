class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& grid,int x,int y,int m,int n){
        if(x>=m || y>=n){
            return 1e5;
        }
        if(x==m-1 && y==n-1){
            return grid[x][y];
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        int op1=solve(grid,x,y+1,m,n);
        int op2=solve(grid,x+1,y,m,n);
        return dp[x][y]=grid[x][y]+min(op1,op2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        dp.resize(m+1,vector<int>(n+1,-1));
        return solve(grid,0,0,m,n);
    }
};