class Solution
{
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // kahns algo
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        //
        // indegree

        vector<int> indegree(V, 0);
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            for (auto &v : adj[i])
            {
                indegree[v]++;
            }
        }
        // zero wale ko que me push
        queue<int> que;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                que.push(i);
                count++;
            };
        };
        while (!que.empty())
        {
            int u = que.front();
            que.pop();
            for (auto &v : adj[u])
            {
                // indegree ko kam karo
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    que.push(v);
                    count++;
                };
            }
        }
        // agar sab ki indegree zero ho gaye yani hame topo sort mil gaya ho gaa and no cycle
        // else cycle
        return count == V ? false : true;
    }
};