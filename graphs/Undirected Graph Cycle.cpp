class Solution
{
public:
    bool isCycleDFS(int u, int parent, unordered_map<int, vector<int>> &adj, vector<bool> &visited)
    {
        visited[u] = true;
        //
        for (auto &v : adj[u])
        {
            if (v == parent)
                continue;
            if (visited[v])
                return true;
            if (!visited[v] && isCycleDFS(v, u, adj, visited))
            {
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
            if (!visited[i] && isCycleDFS(i, -1, adj, visited))
            {
                return true;
            }
        }
        return false;
    }
};