class Solution {
public:
    int dx[8]={-1,1,0,0,1,1,-1,-1};
    int dy[8]={0,0,-1,1,1,-1,1,-1};
    bool isValid(int x,int y,int m,int n){
        if(x<0 || y<0 || x>=m || y>=n)
            return false;
        return true;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>curr=board;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               int living=0;
               for(int k=0;k<8;k++){
                   int x=i+dx[k];
                   int y=j+dy[k];
                   if(isValid(x,y,m,n)){
                       if(curr[x][y] == 1)
                           living++;
                   }
               }
                if(board[i][j] == 0){
                    if(living == 3){
                        board[i][j]=1;
                    }
                } else {
                    if(living <2 || living>3){
                        board[i][j]=0;
                    }
                }
            }
        }
    }
};