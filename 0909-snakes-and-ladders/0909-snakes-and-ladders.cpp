class Solution {
public:
    vector<int>getCoordinates(int number,int n){
        int row= n-(number-1)/n - 1;
        int col= (number-1)%n;
        if(row%2 == n%2){
            return {row,n-1-col};
        } else {
            return {row, col};
        }
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int>q;
        int n=board.size();
        vector<vector<int>>visited(n,vector<int>(n,0));
        q.push(1);
        visited[n-1][0]=1;
        int moves=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int curr=q.front();q.pop();
                if(curr == n*n)
                    return moves;
                for(int k=1;k<=6;k++){
                    if(curr+k>n*n){
                        break;
                    }
                    vector<int>pos = getCoordinates(curr+k,n);
                    int r=pos[0];
                    int c=pos[1];
                    if(visited[r][c]) continue;
                    visited[r][c] = 1;
                    if(board[r][c] == -1){
                        q.push(curr+k);
                    } else {
                        q.push(board[r][c]);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};