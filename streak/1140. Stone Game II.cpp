class Solution
{
public:
    int t[2][101][101];
    int n;
    int solve(vector<int> &piles, int turn, int i, int M)
    {
        if (i >= n)
        {
            return 0;
        }
        if (t[turn][i][M] != -1)
        {
            return t[turn][i][M];
        }
        //
        int result = turn == 1 ? -1 : INT_MAX; // cz ham le rahe alice k leye max and bob k leye min
        int stones = 0;
        for (int x = 1; x <= min(2 * M, n - i); x++)
        {
            stones += piles[x + i - 1];
            if (turn == 1)
            {
                result = max(result, stones + solve(piles, 0, i + x, max(M, x)));
            }
            else
            {
                result = min(result, solve(piles, 1, i + x, max(M, x)));
            }
        }
        return t[turn][i][M] = result;
    }
    int stoneGameII(vector<int> &piles)
    {
        // max lena ha alice ka and min lena ha bob ka - game logic
        n = piles.size();
        memset(t, -1, sizeof(t));
        int result = solve(piles, 1, 0, 1); // piles alice turn, i, M
        return result;
    }
};