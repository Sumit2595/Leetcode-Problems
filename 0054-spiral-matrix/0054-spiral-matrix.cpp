class Solution {
public:
    vector<int>ans;
    vector<vector<int>>vis;
    void solve(vector<vector<int>>& matrix,int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j])
            return;
        vis[i][j]=1;
        ans.push_back(matrix[i][j]);
        solve(matrix,i,j+1,m,n);
        solve(matrix,i+1,j,m,n);
        solve(matrix,i,j-1,m,n);
        while(i>0 && !vis[i-1][j]){
            vis[i-1][j]=1;
            ans.push_back(matrix[i-1][j]);
            i--;
        }
        solve(matrix,i,j+1,m,n);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();  
        vis=vector<vector<int>>(m,vector<int>(n,0));
        solve(matrix,0,0,m,n);
        return ans;
    }
};