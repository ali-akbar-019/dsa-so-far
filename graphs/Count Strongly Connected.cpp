class Solution
{
public:
    void dfsFill(int u, unordered_map<int, vector<int>> &adj, vector<bool> &visited, stack<int> &st)
    {
        visited[u] = true;
        for (auto &v : adj[u])
        {
            if (visited[v])
                continue;
            dfsFill(v, adj, visited, st);
        }
        st.push(u);
    }

    void dfs(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited)
    {
        visited[u] = true;
        for (auto &v : adj[u])
        {
            if (visited[v])
                continue;
            dfs(adj, v, visited);
        }
    }
    int kosaraju(int V, vector<vector<int>> &edges)
    {
        // three steps
        // 1 order -> stack - topological order
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        //
        stack<int> st;
        vector<bool> visited(V, false);
        for (int u = 0; u < V; u++)
        {
            if (!visited[u])
            {
                dfsFill(u, adj, visited, st);
            }
        }
        // ab reverse
        unordered_map<int, vector<int>> revOrder;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            revOrder[v].push_back(u);
        }
        // ab dfs
        visited = vector<bool>(V, false);
        int countSC = 0;
        while (!st.empty())
        {
            int u = st.top();
            st.pop();
            if (!visited[u])
            {
                dfs(revOrder, u, visited);
                countSC += 1;
            }
        }
        return countSC;
    }
};