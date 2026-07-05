class Solution
{
public:
    vector<int> pathsWithMaxScore(vector<string> &board)
    {
        const int MOD = 1e9 + 7;

        int m = board.size();
        int n = board[0].size();

        vector<vector<pair<int, int>>> dp(m, vector<pair<int, int>>(n, {-1, 0}));
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {1, 1}};

        dp[m - 1][n - 1] = {0, 1};

        int num;

        for (int r = m - 1; r >= 0; r--)
        {
            for (int c = n - 1; c >= 0; c--)
            {

                if (board[r][c] == 'S')
                    continue;
                if (board[r][c] == 'X')
                    continue;

                if (board[r][c] == 'E')
                    num = 0;
                else
                    num = board[r][c] - '0';

                int maxNum = -1;
                int maxKaCount = 0;

                for (auto &dir : dirs)
                {
                    int nx = r + dir[0];
                    int ny = c + dir[1];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    if (dp[nx][ny].first == -1)
                        continue;

                    if (dp[nx][ny].first > maxNum)
                    {
                        maxNum = dp[nx][ny].first;
                        maxKaCount = dp[nx][ny].second;
                    }
                    else if (dp[nx][ny].first == maxNum)
                    {
                        maxKaCount = (maxKaCount + dp[nx][ny].second) % MOD;
                    }
                }

                if (maxNum != -1)
                {
                    dp[r][c].first = num + maxNum;
                    dp[r][c].second = maxKaCount;
                }
            }
        }

        if (dp[0][0].first == -1)
            return {0, 0};

        return {dp[0][0].first, dp[0][0].second};
    }
};