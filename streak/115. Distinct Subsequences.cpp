class Solution
{
public:
    typedef unsigned long long ull;
    int dp[1001][1001];
    ull solve(string s, string t, int n, int m)
    {
        // peche se character match krna shuru karo
        if (m == 0)
        {
            // pora match ho gaya
            return dp[n][m] = 1;
        }
        if (n == 0)
        {
            // means k pora match nahi ho paya t se
            return dp[n][m] = 0;
        }
        // dp me present ha
        if (dp[n][m] != -1)
        {
            return dp[n][m];
        }
        // agar to match ho gaya
        if (s[n - 1] == t[m - 1])
        {
            // do possibilities ha ya to isi ko match kar k aage barho ya to s ko aage barhao and match karo t se
            return dp[n][m] = solve(s, t, n - 1, m - 1) + solve(s, t, n - 1, m);
        }
        else
        {
            // match nahi huwa
            return dp[n][m] = solve(s, t, n - 1, m);
        }

        return -1;
    }
    int numDistinct(string s, string t)
    {

        int n = s.length();
        int m = t.length();
        memset(dp, -1, sizeof(dp));
        return solve(s, t, n, m);
    }
};