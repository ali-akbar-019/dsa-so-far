class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // solving using the bfs (Kahns algorithm)
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        //
        // pehle to indegree nikal lo
        // fir jis ki indegree zero ho use ko push kar do queue me
        // fir pop karo and indegree minus karo and check akro agar 0 ha then push
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto &v : adj[i])
            {
                indegree[v]++;
            }
        }
        //
        queue<int> que;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                que.push(i);
            }
        }
        //
        vector<int> result;
        while (!que.empty())
        {
            int u = que.front();
            // resule me dal do q k zero indegree wala tha and ise pop kar deya
            result.push_back(u);
            que.pop();
            for (auto &v : adj[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    que.push(v);
                }
            }
        }
        return result;
    }
};