class Solution
{
public:
    void dfs(int u, vector<bool> &visited, vector<vector<int>> &adj)
    {
        visited[u] = true;
        for (int v = 0; v < adj.size(); v++)
        {
            if (adj[u][v] == 1 && !visited[v])
            {
                visited[v] = true;
                dfs(v, visited, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int V = isConnected.size();
        vector<bool> visited(V, false);
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                count++; // means k aik province ho gaya
                dfs(i, visited, isConnected);
            }
        }
        return count;
    }
};