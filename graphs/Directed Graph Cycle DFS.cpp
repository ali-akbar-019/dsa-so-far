class Solution
{
public:
    bool isCyclicDFS(int u, vector<int> &visited, vector<int> &inRecursion, unordered_map<int, vector<int>> &adj)
    {
        // visit kar do and recursion me dal do
        visited[u] = true;
        inRecursion[u] = true;
        // ab adj nodes check karo
        for (auto &v : adj[u])
        {
            if (!visited[v] && isCyclicDFS(v, visited, inRecursion, adj))
            {
                return true;
            }
            else if (inRecursion[v] == true)
            {
                return true; // means k same recursion me ha and ham already visited node pe ha
            }
        }
        // in recursion se nikal do
        inRecursion[u] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // using dfs
        // we have to also make sure that the nodes are in teh same recursion
        // then we will say that there is the cycle else not
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v); // directed
        }
        vector<int> visited(V, false);
        vector<int> inRecursion(V, false);
        //
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && isCyclicDFS(i, visited, inRecursion, adj))
            {
                return true;
            }
        }
        return false;
    }
};