class Solution
{
public:
    bool checkBipartiteBFS(int curr, vector<vector<int>> &graph, vector<int> &colors, int currColor)
    {
        colors[curr] = currColor;
        queue<int> que;
        que.push(curr);
        while (!que.empty())
        {
            int u = que.front();
            que.pop();
            for (auto &v : graph[u])
            {
                if (colors[u] == colors[v])
                {
                    return false;
                }
                if (colors[v] == -1)
                {
                    // un assigned yet
                    int vColor = 1 - colors[u];
                    colors[v] = vColor;
                    que.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        // using bfs this time
        int V = graph.size();
        vector<int> colors(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (colors[i] == -1)
            {
                if (checkBipartiteBFS(i, graph, colors, 1) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};