class Solution
{
public:
    int dp[301][27][27];
    int dist(int a, int b)
    {
        //
        if (a == -1)
        {
            return 0; // finger not used yet
        }
        //
        int x1 = a / 6;
        int y1 = a % 6;
        int x2 = b / 6;
        int y2 = b % 6;

        return abs(x1 - x2) + abs(y1 - y2);
    }
    int solve(string &word, int i, int f1, int f2)
    {
        if (i == word.size())
        {
            // means
            return 0;
        }
        //
        if (dp[i][f1 + 1][f2 + 1] != -1)
        {
            return dp[i][f1 + 1][f2 + 1];
        }
        //
        int curr = word[i] - 'A'; // index
        //
        int useF1 = dist(f1, curr) + solve(word, i + 1, curr, f2);
        int useF2 = dist(f2, curr) + solve(word, i + 1, f1, curr);

        return dp[i][f1 + 1][f2 + 1] = min(useF1, useF2);
    }
    int minimumDistance(string word)
    {
        memset(dp, -1, sizeof(dp));
        return solve(word, 0, -1, -1);
    }
};