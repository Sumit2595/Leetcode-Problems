class Solution
{
    public:
        #define INF 2147483647
        #define pp pair<int, int>
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};
        bool isValid(int x, int y, int rows, int cols){
            return x>=0 and x<rows and y>=0 and y<cols;
        }
        void wallsAndGates(vector<vector < int>> &rooms)
        {
            queue<pp> q;	
            int row = rooms.size();
            int col = rooms[0].size();
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (rooms[i][j] == 0)
                    {
                        q.push({ i,j });
                    }
                }
            }
            int dist = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto pr = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int xx = pr.first + dx[i];
                    int yy = pr.second + dy[i];
                    if(isValid(xx, yy, row, col) and rooms[xx][yy] == INF){
                        q.push({xx,yy});
                        rooms[xx][yy] = dist;
                    }
                }
            }
            dist++;
        }
        
        }
};