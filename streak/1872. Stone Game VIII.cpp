// recursion
class Solution
{
public:
    int n;
    int solve(int i, vector<int> &prefixSum)
    {
        if (i == n - 1)
        {
            return prefixSum[n - 1];
        }
        //
        int take = prefixSum[i] - solve(i + 1, prefixSum);
        int skip = solve(i + 1, prefixSum);
        return max(take, skip);
    }
    int stoneGameVIII(vector<int> &stones)
    {
        // revusrion solution
        n = stones.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = stones[0];
        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }
        //

        return solve(1, prefixSum);
    }
};
// bottom up
class Solution
{
public:
    int n;

    int stoneGameVIII(vector<int> &stones)
    {
        // revusrion solution
        n = stones.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = stones[0];
        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }
        //

        vector<int> t(n, 0);
        t[n - 1] = prefixSum[n - 1];
        for (int i = n - 2; i >= 1; i--)
        {
            int take = prefixSum[i] - t[i + 1];
            int skip = t[i + 1];
            t[i] = max(take, skip);
        }
        return t[1];
    }
};