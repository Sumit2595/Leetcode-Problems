class Solution {
public:
    bool DFS(vector<vector<int>>&maze, vector<vector<int>>&visited, vector<int> start, vector<int>destination){
        if(visited[start[0]][start[1]] == 1) return false;
        if(start[0] == destination[0] and start[1] == destination[1]) return true;
        visited[start[0]][start[1]] = 1;
        int left = start[1] - 1, right = start[1] + 1, up = start[0] - 1, down = start[0] + 1;
        
        // we are moving rightward till wall or boundary not hit
        while(right < maze[0].size() and maze[start[0]][right] == 0) right++;
        if(DFS(maze,visited,{start[0],right-1},destination)) return true;
        
        // we are moving leftward till wall or boundary not hit
        while(left >= 0 and maze[start[0]][left] == 0) left--;
        if(DFS(maze,visited,{start[0],left+1},destination)) return true;
        
        // we are moving upward till wall or boundary not hit
        while(up >= 0 and maze[up][start[1]] == 0) up--;
        if(DFS(maze,visited,{up+1,start[1]},destination)) return true;
        
        // we are moving downward till wall or boundary not hit
        while(down < maze.size() and maze[down][start[1]] == 0) down++;
        if(DFS(maze,visited,{down-1, start[1]},destination)) return true;
        
        return false; 
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int rows = maze.size();
        int cols = maze[0].size();
        vector<vector<int>> visited(rows,vector<int>(cols,0));
        return DFS(maze,visited,start, destination);
    }
};
