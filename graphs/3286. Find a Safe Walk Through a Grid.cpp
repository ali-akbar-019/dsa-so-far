class Solution
{
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        //  0 and 1 BFS
        int m = grid.size();
        int n = grid[0].size();

        //
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        deque<pair<int, int>> dq;
        // start is 0,0
        dq.push_front({0, 0});
        result[0][0] = grid[0][0];
        while (!dq.empty())
        {
            auto [r, c] = dq.front();
            dq.pop_front();
            // ab is se ham  4 direction me ja sakte ha
            for (auto &dir : directions)
            {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                {
                    continue;
                }
                if (result[nr][nc] > result[r][c] + grid[nr][nc])
                {
                    result[nr][nc] = result[r][c] + grid[nr][nc];
                    // agar to 1 ha weight then dq k back pe push karo
                    //  else front pe
                    if (grid[nr][nc] == 1)
                    {
                        dq.push_back({nr, nc});
                    }
                    else
                    {
                        dq.push_front({nr, nc});
                    }
                }
            }
        }

        int x = result[m - 1][n - 1];
        return health - x >= 1;
    }
};