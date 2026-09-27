class Solution
{
public:
    typedef pair<int, int> P;
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int orangesRotting(vector<vector<int>> &grid)
    {
        //
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        queue<P> que;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
                else if (grid[i][j] == 2)
                {
                    que.push(make_pair(i, j));
                }
            }
        }
        //
        if (fresh == 0)
        {
            return 0;
        }
        //
        int minutes = 0;
        while (!que.empty())
        {
            int currLevelSize = que.size();
            while (currLevelSize--)
            {
                auto orange = que.front();
                que.pop();
                int i = orange.first;
                int j = orange.second;
                for (auto &dir : directions)
                {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                    if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n)
                    {
                        continue;
                    }
                    //
                    if (grid[new_i][new_j] == 1)
                    {
                        grid[new_i][new_j] = 2;
                        fresh -= 1;
                        que.push({new_i, new_j});
                    }
                }
            }
            minutes += 1;
        }
        return fresh == 0 ? minutes - 1 : -1;
    }
};