// DAG
// Directed Acyclic Graph
class Solution
{
public:
    void topoSortDFS(int u, vector<bool> &visited, stack<int> &st, unordered_map<int, vector<int>> &adj)
    {
        visited[u] = true;
        for (auto &v : adj[u])
        {
            if (!visited[v])
            {
                topoSortDFS(v, visited, st, adj);
            }
        }
        // bacho ko pehle stack me dalo
        // fir parent ko dalo
        st.push(u);
    }
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<bool> visited(V, false);
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                topoSortDFS(i, visited, st, adj);
            }
        }
        //
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};