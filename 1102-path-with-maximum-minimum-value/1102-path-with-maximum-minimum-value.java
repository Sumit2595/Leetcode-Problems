class Solution {
    int R;
    int C;
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    public int maximumMinimumPath(int[][] grid) {
        R = grid.length;
        C = grid[0].length;
        boolean[][] visited = new boolean[R][C];
        Queue<int[]> dq = new PriorityQueue<>((a,b)->b[2]-a[2]);
        dq.add(new int[]{0,0,grid[0][0]});
        visited[0][0] =  true;
        while(!dq.isEmpty()){
            int s= dq.size();
            for(int k =0;k<s;k++){
                int curr[] = dq.poll();
                int currX = curr[0];
                int currY = curr[1];
                if(currX==R-1 && currY==C-1){
                    return curr[2];
                }
                for(int i=0;i<4;i++){
                    int x = dx[i] + currX;
                    int y = dy[i] + currY;
                    if(x>=0 && x<R && y>=0 && y<C && !visited[x][y]){
                        visited[x][y] = true;
                        dq.add(new int[]{x,y,Math.min(curr[2],grid[x][y])});//min in the path
                    }
                } 
            }
            
        }
        return -1;
    }
}