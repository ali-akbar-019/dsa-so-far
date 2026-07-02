class Solution
{
public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        // okay we will use bfs to solve this question
        int m = grid.size();
        int n = grid[0].size();
        // best array
        vector<vector<int>> best(m, vector<int>(n, -1));
        //
        queue<tuple<int, int, int>> q;
        //
        int startHealth = health - grid[0][0];
        if (startHealth <= 0)
        {
            return false;
        }
        //
        best[0][0] = startHealth;
        q.push({0, 0, startHealth});
        //
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        //
        while (!q.empty())
        {
            auto [r, c, h] = q.front();
            q.pop();
            if (r == m - 1 && c == n - 1 && h > 0)
            {
                return true;
            }
            //
            for (int k = 0; k < 4; k++)
            {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                {
                    continue;
                }
                //
                int nh = h - grid[nr][nc];
                if (nh <= 0)
                {
                    continue;
                }
                if (best[nr][nc] >= nh)
                {
                    continue;
                }

                best[nr][nc] = nh;
                q.push({nr, nc, nh});
            }
        }
        return false;
    }
};