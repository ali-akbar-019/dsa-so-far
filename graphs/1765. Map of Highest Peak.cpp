class Solution
{
public:
    typedef pair<int, int> P;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        // multisource BFS , jaha jaha 0 ha waha se BFS lagao , bcz simple bfs , dfs se no answer
        int m = isWater.size();
        int n = isWater[0].size();
        queue<P> que;
        // agar water ho then value zero ho gi height ki
        vector<vector<int>> heights(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j] == 1)
                {
                    heights[i][j] = 0;
                    que.push({i, j});
                }
            }
        }
        //
        while (!que.empty())
        {
            int size = que.size();
            while (size--)
            {
                pair<int, int> node = que.front();
                int i = node.first;
                int j = node.second;
                que.pop();
                for (auto &dir : directions)
                {
                    int i_ = dir[0];
                    int j_ = dir[1];
                    int new_i = i + i_;
                    int new_j = j + j_;
                    if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || heights[new_i][new_j] != -1)
                    {
                        continue;
                    }
                    heights[new_i][new_j] = heights[i][j] + 1;
                    que.push({new_i, new_j});
                }
            }
        }
        return heights;
    }
};