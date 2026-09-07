class Solution
{
public:
    int distinctSubseqII(string s)
    {
        int n = s.length();
        const int MOD = 1e9 + 7;

        // dp[i] stores the number of distinct subsequences using the first i characters
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case: 1 for the empty string ""

        // Stores the last seen 1-based DP index for each character
        unordered_map<char, int> mp;

        for (int i = 0; i < n; i++)
        {
            // Each new character doubles the existing combinations
            dp[i + 1] = (dp[i] * 2) % MOD;

            // If the character was seen before, subtract the subsequences
            // that were created just before its previous occurrence.
            if (mp.count(s[i]))
            {
                dp[i + 1] = (dp[i + 1] - dp[mp[s[i]] - 1] + MOD) % MOD;
            }

            // Record the current 1-based index for this character
            mp[s[i]] = i + 1;
        }

        // Subtract 1 to exclude the empty string subsequence ""
        return (dp[n] - 1 + MOD) % MOD;
    }
};
