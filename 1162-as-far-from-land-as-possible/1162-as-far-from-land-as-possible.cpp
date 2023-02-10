class Solution {
public:
    struct Pair{
        int x,y;
    };
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<Pair>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    q.push({i,j});
                }
            }
        }
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                Pair tp=q.front();q.pop();
                int x=tp.x;
                int y=tp.y;
                if(x-1>=0 && grid[x-1][y]==0){
                    grid[x-1][y]=1;
                    q.push({x-1,y});
                }
                if(x+1<n && grid[x+1][y]==0){
                    grid[x+1][y]=1;
                    q.push({x+1,y});
                }
                if(y-1>=0 && grid[x][y-1]==0){
                    grid[x][y-1]=1;
                    q.push({x,y-1});
                }
                if(y+1<n && grid[x][y+1]==0){
                    grid[x][y+1]=1;
                    q.push({x,y+1});
                }
            }
            if(q.size() > 0)
            level++;
        }
      return level == 0 ? -1 :level;  
    }
};