class Solution
{
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        //
        ll total = 0;
        vector<ll> rowSum(m, 0);
        vector<ll> colSum(n, 0);
        //
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                total += grid[i][j];
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }
        //
        // vertical split
        ll uper = 0;
        for (int i = 0; i < m - 1; i++)
        {
            uper += rowSum[i];
            if (uper == total - uper)
            {
                return true;
            }
        }
        //
        ll left = 0;
        for (int j = 0; j < n - 1; j++)
        {
            left += colSum[j];
            if (left == total - left)
            {
                return true;
            }
        }
        return false;
    }
};