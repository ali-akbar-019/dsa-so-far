class Solution
{
public:
    int n;
    int m;
    int solve(vector<vector<int>> &grid, int k, int cost, int i, int j, vector<vector<vector<int>>> &dp)
    {
        if (i >= m || j >= n)
        {
            return INT_MIN;
        }
        //
        int newCost = cost + (grid[i][j] > 0);
        if (newCost > k)
        {
            return dp[i][j][cost] = INT_MIN;
        }
        //
        if (i == m - 1 && j == n - 1)
        {
            return dp[i][j][cost] = grid[i][j];
        }
        if (dp[i][j][cost] != -1)
        {
            return dp[i][j][cost];
        }
        int right = solve(grid, k, newCost, i, j + 1, dp);
        int down = solve(grid, k, newCost, i + 1, j, dp);
        int bestSol = max(right, down);
        if (bestSol == INT_MIN)
        {
            return dp[i][j][cost] = INT_MIN;
        }
        //
        return dp[i][j][cost] = bestSol + grid[i][j];
    }
    int maxPathScore(vector<vector<int>> &grid, int k)
    {

        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
        int ans = solve(grid, k, 0, 0, 0, dp);
        return ans == INT_MIN ? -1 : ans;
    }
};