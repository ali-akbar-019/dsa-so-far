class Solution
{
public:
    int t[1001][1001];
    int M = 1e9 + 7;
    int solve(int n, int k, int i)
    {
        if (k == 0)
        {
            return 1;
        }
        if (i >= n)
        {
            return 0;
        }
        if (t[k][i] != -1)
        {
            return t[k][i];
        }
        //
        // take and skip
        long long take = 0;
        for (int j = i + 1; j <= n - 1; j++)
        {
            take = (take + solve(n, k - 1, j)) % M;
        }
        long long skip = solve(n, k, i + 1) % M;
        return t[k][i] = (take + skip) % M;
    }
    int numberOfSets(int n, int k)
    {
        memset(t, -1, sizeof(t));
        // recursion wala way
        return solve(n, k, 0) % M;
    }
};
class Solution
{
public:
    int M = 1e9 + 7;
    int dp[1001][1001];

    int numberOfSets(int n, int K)
    {

        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = (i < n) ? 1 : 0;
        }

        for (int k = 1; k <= K; k++)
        {

            vector<int> prevRowSum(n + 1, 0);

            // prevRowSum[x] = dp[k-1][x] + dp[k-1][x+1] + ... + dp[k-1][n-1]
            for (int x = n - 1; x >= 0; x--)
            {
                prevRowSum[x] = (prevRowSum[x + 1] + dp[k - 1][x]) % M;
            }

            for (int i = n - 1; i >= 0; i--)
            {

                int skip = dp[k][i + 1];

                int take = prevRowSum[i + 1];
                // dp[k-1][i+1] + dp[k-1][i+2] ...... + dp[k-1][n-1]

                dp[k][i] = (take + skip) % M;
            }
        }

        return dp[K][0];
    }
};