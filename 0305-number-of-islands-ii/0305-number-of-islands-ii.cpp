class Solution {
    public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> res;
        roots = vector<int>(m * n, -1);
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int island = 0;
        for (auto pos : positions) {
            int x = pos[0], y = pos[1], idx_p = x * n + y;
            if(roots[idx_p] != -1) {
                res.push_back(island);
                continue;
            }
            roots[idx_p] = idx_p;
            ++island;
            for (auto dir : dirs) {
                int row = x + dir.first, col = y + dir.second, idx_new = row * n + col;
                if (row >= 0 && row < m && col >= 0 && col < n && roots[idx_new] != -1) {
                    int rootNew = findRoot(idx_new), rootPos = findRoot(idx_p);
                    if (rootPos != rootNew) {
                        roots[rootPos] = rootNew;
                        --island;
                    }
                }
            }
            res.push_back(island);
        }
        return res;
    }

    private:
    vector<int> roots;
    int findRoot(int idx) {
        while(idx != roots[idx]) {
            roots[idx] = roots[roots[idx]]; 
            idx = roots[idx];
        }
        return idx;
    }
};