class Solution
{
public:
    void dfs(int u, unordered_map<int, vector<int> > &adj, vector<bool> &visited, vector<int> &result)
    {
        if (visited[u])
            return;
        visited[u] = true;
        // result me push back karo
        result.push_back(u);
        // ab is k neighbors deko
        for (auto &v : adj[u])
        {
            if (visited[v])
                continue;
            dfs(v, adj, visited, result);
        }
    }
    vector<int> dfs(vector<vector<int> > &mp)
    {
        // convert to map
        unordered_map<int, vector<int> > adj;
        for (int u = 0; u < mp.size(); u++)
        {
            for (int v = 0; v < mp[u].size(); v++)
            {
                adj[u].push_back(mp[u][v]);
            }
        }

        vector<int> result;
        vector<bool> visited(mp.size(), false);
        int u = 0;
        dfs(u, adj, visited, result);
        return result;
    }
};