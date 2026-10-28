class Solution {
public:
    void dfs(int r, int c, int R, int C, vector<vector<int>> &visit, vector<vector<char>>& grid) {
        int nr, nc;
        visit[r][c] = 1;
        vector<int> dir = {-1, 0, 1, 0, -1};

        for (int d=0;d<dir.size()-1;d++) {
            nr = r+dir[d]; 
            nc = c+dir[d+1];
            if (nr>=0 && nr<R && nc>=0 && nc<C && grid[nr][nc]=='1' && !visit[nr][nc]) {
                dfs(nr, nc, R, C, visit, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int r, c, ans = 0;
        r = grid.size();
        c = grid[0].size();
        vector<vector<int>> visit(r, vector<int> (c, 0));

        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                if (grid[i][j] == '1' && !visit[i][j]) {
                    ans++;
                    dfs(i, j, r, c, visit, grid);
                }
            }
        }
        return ans;
    }
};
