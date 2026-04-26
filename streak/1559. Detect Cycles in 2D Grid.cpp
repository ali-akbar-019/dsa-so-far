class Solution
{
public:
    int n, m;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfsCheckCycle(int i, int j, int prev_i, int prev_j, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        if (visited[i][j] == true)
        {
            // matlab ham ghoom k wahi agae ha yaha se start keya
            return true;
        }
        visited[i][j] = true;
        // sari directions check karo
        for (auto &dir : directions)
        {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] == grid[i][j])
            {
                //
                if (new_i == prev_i && new_j == prev_j)
                {
                    continue;
                }
                if (dfsCheckCycle(new_i, new_j, i, j, grid, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>> &grid)
    {
        // using dfs to solve this
        // har aik non visited cell pe jao and waha se check karo k koi ban raha ha cycle ya nahi
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && dfsCheckCycle(i, j, i, j, grid, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};