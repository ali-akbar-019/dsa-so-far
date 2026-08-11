class Solution
{
public:
    vector<vector<int>> directions{{1, 1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
    typedef pair<int, pair<int, int>> P;
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        // dijkstras algorithm
        int m = grid.size();
        int n = grid[0].size();
        if (m == 0 || n == 0 || grid[0][0] == 1)
        {
            return -1;
        }
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        result[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty())
        {
            int dist = pq.top().first;
            pair<int, int> node = pq.top().second;
            int x = node.first;
            int y = node.second;
            pq.pop();
            if (dist > result[x][y])
            {
                continue;
            }
            for (auto &dir : directions)
            {
                int d = 1;
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                if (x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && grid[x_][y_] != 1 && dist + d < result[x_][y_])
                {
                    result[x_][y_] = dist + d;
                    grid[x_][y_] = 1;
                    pq.push({dist + d, {x_, y_}});
                }
            }
        }
        if (result[m - 1][n - 1] == INT_MAX)
        {
            return -1;
        }
        return result[m - 1][n - 1] + 1; // no of zeros covered
    }
};