class Solution
{
public:
    void dfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int &e, int &v, int i)
    {
        if (visited[i])
            return;
        visited[i] = true;
        v++;
        e += adj[i].size();

        // sare neighbors k leye karo dfs
        for (auto &ngbr : adj[i])
        {
            dfs(adj, visited, e, v, ngbr);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        // adj list
        unordered_map<int, vector<int>> adj;
        //
        int result = 0;

        // make the adj list
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // now dfs
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;
            // call karo dfs ko
            int e = 0;
            int v = 0;
            dfs(adj, visited, e, v, i);
            if ((v * (v - 1)) == e)
                result++;
        }
        return result;
    }
};