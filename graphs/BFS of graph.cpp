class Solution
{
public:
    void bfs(int u, vector<bool> &visited, vector<int> &result,
             vector<vector<int> > &adj)
    {
        if (visited[u])
            return;
        queue<int> que;
        que.push(u);
        visited[u] = true;
        result.push_back(u);
        // ab bfs
        while (!que.empty())
        {
            int u = que.front();
            que.pop();

            for (auto &v : adj[u])
            {
                if (visited[v])
                    continue;
                que.push(v);
                visited[v] = true;
                result.push_back(v);
            }
        }
    }
    vector<int> bfs(vector<vector<int> > &adj)
    {
        int V = adj.size();
        vector<bool> visited(V, false);
        vector<int> result;
        bfs(0, visited, result, adj);
        return result;
    }
};