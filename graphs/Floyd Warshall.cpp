class Solution
{
public:
    void floydWarshall(vector<vector<int>> &dist)
    {
        // easy floyd warshal algo
        int m = dist.size();
        int n = dist[0].size();
        for (int k = 0; k < m; k++)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == 100000000 ||
                        dist[k][j] == 100000000)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
};