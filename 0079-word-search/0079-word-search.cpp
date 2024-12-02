class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,
               int i,int j,int w,int x,int y,int n){
        if(w>=n)
            return true;
        if(i<0 || i>=x || j<0 || j>=y || board[i][j]!=word[w])
            return false;
        char ch=board[i][j];
        board[i][j]='#';
        bool up=solve(board,word,i+1,j,w+1,x,y,n);
        bool down=solve(board,word,i-1,j,w+1,x,y,n);
        bool right=solve(board,word,i,j+1,w+1,x,y,n);
        bool left=solve(board,word,i,j-1,w+1,x,y,n);
        board[i][j]=ch;
        return up || down || right || left;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int x=board.size();
        int y=board[0].size();
        int n=word.size();
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(solve(board,word,i,j,0,x,y,n))
                    return true;
            }
        }
        return false;
    }
};