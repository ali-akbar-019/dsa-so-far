class Solution
{
public:
    void dfs(unordered_map<int, vector<int> > &adj, int u, vector<int> &visited)
    {
        visited[u] = true;
        for (auto &v : adj[u])
        {
            if (visited[v])
                continue;
            dfs(adj, v, visited);
        }
    }
    bool isConnected(unordered_map<int, vector<int> > &adj, int V)
    {
        // kisi aik node se start karo jis ki degree non zero ho then sare k sare comp visit hone chahie
        int nonZeroIndegreeVertice = -1;
        for (int i = 0; i < V; i++)
        {
            if (adj[i].size() > 0)
            {
                nonZeroIndegreeVertice = i;
                break;
            }
        }
        if (nonZeroIndegreeVertice == -1)
            return true;
        vector<int> visited(V, false);
        dfs(adj, nonZeroIndegreeVertice, visited);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false && adj[i].size() > 0)
            {
                return false;
            }
        }
        return true;
    }
    int isEulerCircuit(int V, vector<vector<int> > &edges)
    {
        // pehle check karo k graph connected ha pora
        unordered_map<int, vector<int> > adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // is connected
        if (isConnected(adj, V) == false)
        {
            return 0;
        }
        // count odd degree
        int oddDegreeCount = 0;
        for (int i = 0; i < V; i++)
        {
            if (adj[i].size() % 2 != 0)
            {
                oddDegreeCount++;
            }
        }
        if (oddDegreeCount > 2)
            return 0;
        if (oddDegreeCount == 2)
            return 1;
        return 2;
    }
};
// -----/
