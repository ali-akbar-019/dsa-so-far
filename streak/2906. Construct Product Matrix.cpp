class Solution
{
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid)
    {
        // alr we gonna use the prefix sum and the suffix sum to find the result
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 12345;
        vector<vector<int>> p(m, vector<int>(n, 0));
        // find the suffix product
        long long suffix = 1;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                p[i][j] = suffix;
                suffix = (suffix * grid[i][j]) % MOD;
            }
        }
        // now the prefix product and the result
        long long prefix = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                p[i][j] = (prefix * p[i][j]) % MOD;
                prefix = (prefix * grid[i][j]) % MOD;
            }
        }
        return p;
    }
};