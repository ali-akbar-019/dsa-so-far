class Solution
{
public:
    typedef long long ll;
    ll total = 0;
    bool checkHorizontalCuts(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        unordered_set<ll> st;
        ll top = 0;
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                st.insert(grid[i][j]);
                top += grid[i][j];
            }
            ll bottom = total - top;
            ll diff = top - bottom;
            if (diff == 0)
            {
                return true;
            }
            if (diff == ll(grid[0][0]))
            {
                return true;
            }
            if (diff == ll(grid[0][n - 1]))
            {
                return true;
            }
            if (diff == ll(grid[i][0]))
            {
                return true;
            }
            if (i > 0 && n > 1 && st.count(diff))
            {
                return true;
            }
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                total += grid[i][j];
            }
        }
        if (checkHorizontalCuts(grid))
        {
            return true;
        }
        reverse(begin(grid), end(grid));
        if (checkHorizontalCuts(grid))
        {
            return true;
        }
        // now for the vertical checks
        // take transpose and do the same row thing
        // orignal grid
        reverse(begin(grid), end(grid));
        // vertical cut
        vector<vector<int>> transposeGrid(n, vector<int>(m)); // transpose le rahe ho to m - n ban jaye ga
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                transposeGrid[j][i] = grid[i][j];
            }
        }
        if (checkHorizontalCuts(transposeGrid))
        {
            return true;
        }
        reverse(begin(transposeGrid), end(transposeGrid));
        if (checkHorizontalCuts(transposeGrid))
        {
            return true;
        }
        return false;
    }
};