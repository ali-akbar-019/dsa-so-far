class Solution
{
public:
    bool isCycle;
    bool dfs(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &inRecursion, stack<int> &st)
    {
        visited[u] = true;
        inRecursion[u] = true;
        for (auto &v : adj[u])
        {
            if (!visited[v] && dfs(adj, v, visited, inRecursion, st))
            {
                isCycle = true;
                return true;
            }
            else if (inRecursion[v])
            {
                isCycle = true;
                return true;
            }
        }
        // pehle mere bacho ko dalo fir muje
        st.push(u);
        inRecursion[u] = false;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>> &pr)
    {
        // cycle detection b check karo and topological sort b nikal lo
        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);
        isCycle = false;
        unordered_map<int, vector<int>> adj;
        stack<int> st;
        for (auto &preq : pr)
        {
            int a = preq[0];
            int b = preq[1];
            // b--->a
            adj[b].push_back(a);
        }
        //
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(adj, i, visited, inRecursion, st);
            }
        }
        if (isCycle)
        {
            return {};
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};