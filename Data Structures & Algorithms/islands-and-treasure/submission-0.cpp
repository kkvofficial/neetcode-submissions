class Solution {
public:
    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid) {
        int r, c, nr, nc, R = grid.size(), C = grid[0].size();
        vector<int> direc = {-1, 0, 1, 0, -1};

        while(!q.empty()) {
            pair<int, int> coord = q.front();
            q.pop();

            r = coord.first;
            c = coord.second;

            for (int d=0;d<direc.size()-1;d++) {
                nr = r + direc[d];
                nc = c + direc[d+1];

                if (nr>=0 && nc>=0 && nr<R && nc<C && grid[r][c]+1 < grid[nr][nc]) {
                    grid[nr][nc] = grid[r][c]+1;
                    q.push({nr, nc});
                }
            }

        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        queue<pair<int, int>> q;

        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }
        bfs(q, grid);
    }
};
