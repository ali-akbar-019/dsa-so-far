class Solution
{
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>> &queries)
    {
        const int MOD = 1e9 + 7;
        int n = s.length();

        // Prefix arrays
        vector<long long> prefixSum(n, 0);
        vector<int> prefixCount(n, 0);
        vector<long long> prefixX(n, 0);

        // Powers of 10 modulo MOD
        vector<long long> power10(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        // Initialize
        int dig = s[0] - '0';
        prefixSum[0] = dig;
        prefixCount[0] = (dig != 0 ? 1 : 0);
        prefixX[0] = (dig != 0 ? dig : 0);

        // Build prefix arrays
        for (int i = 1; i < n; i++)
        {
            dig = s[i] - '0';

            prefixSum[i] = (prefixSum[i - 1] + dig) % MOD;
            prefixCount[i] = prefixCount[i - 1] + (dig != 0 ? 1 : 0);

            if (dig != 0)
                prefixX[i] = (prefixX[i - 1] * 10 + dig) % MOD;
            else
                prefixX[i] = prefixX[i - 1];
        }

        vector<int> ans;

        for (auto &q : queries)
        {
            int l = q[0];
            int r = q[1];
            long long sum = prefixSum[r];
            if (l > 0)
                sum = (sum - prefixSum[l - 1] + MOD) % MOD;

            int nonZeroDigCount = prefixCount[r];
            if (l > 0)
                nonZeroDigCount -= prefixCount[l - 1];

            long long x = prefixX[r];
            if (l > 0)
            {
                x = (x - (prefixX[l - 1] * power10[nonZeroDigCount]) % MOD + MOD) % MOD;
            }

            ans.push_back((sum * x) % MOD);
        }

        return ans;
    }
};