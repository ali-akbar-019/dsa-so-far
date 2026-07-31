class Solution
{
public:
    bool isCycleBFS(int u, unordered_map<int, vector<int>> &adj, vector<bool> &visited)
    {
        queue<pair<int, int>> que;
        que.push({u, -1});
        visited[u] = true;
        while (!que.empty())
        {
            pair<int, int> P = que.front();
            que.pop();
            int source = P.first;
            int parent = P.second;
            //
            for (auto &v : adj[source])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    que.push({v, source});
                }
                else if (v != parent)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // dfs karo, parent ko skip kar dena
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            // q k koi node agar alag ho then sari nodes pe check karo
            if (!visited[i] && isCycleBFS(i, adj, visited))
            {
                return true;
            }
        }
        return false;
    }
};
// TC = O(V + E)