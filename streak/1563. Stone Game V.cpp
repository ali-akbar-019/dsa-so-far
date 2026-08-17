class Solution
{
public:
    int t[501][501];
    int solve(int l, int r, vector<int> &cumSum)
    {
        if (l >= r)
            return 0;
        if (t[l][r] != -1)
            return t[l][r];
        int score = 0;
        for (int mid = l; mid < r; mid++)
        {
            int leftSum = cumSum[mid] - (l > 0 ? cumSum[l - 1] : 0);
            int rightSum = cumSum[r] - cumSum[mid];

            if (leftSum < rightSum)
            {
                score = max(score, leftSum + solve(l, mid, cumSum));
            }
            else if (rightSum < leftSum)
            {
                score = max(score, rightSum + solve(mid + 1, r, cumSum));
            }
            else
            {
                score = max({score, leftSum + solve(l, mid, cumSum), rightSum + solve(mid + 1, r, cumSum)});
            }
        }
        return t[l][r] = score;
    }
    int stoneGameV(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        vector<int> cumSum(n, 0);
        cumSum[0] = stoneValue[0];
        memset(t, -1, sizeof(t));
        for (int i = 1; i < n; i++)
        {
            cumSum[i] = cumSum[i - 1] + stoneValue[i];
        }
        int l = 0;
        int r = n - 1;
        return solve(l, r, cumSum);
    }
};