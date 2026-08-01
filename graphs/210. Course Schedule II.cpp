class Solution
{
public:
    // top sort return kare ga ,lets suppose 0, 1 to is ka matlab ha k 0 one se pehle araha ha k nahi
    // sam agar ho 0 2 1 3 , means k 2 zero k bad araha ha k nahi , 3 one k bad, 0 sab se pehle. like aik sorted order
    vector<int> topologicalSort(unordered_map<int, vector<int>> &adj, vector<int> &indegree, int n)
    {
        queue<int> que;
        // jis ki indegree zero k use push karo
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                que.push(i);
                result.push_back(i);
            }
        }
        while (!que.empty())
        {
            int u = que.front();
            que.pop();
            for (auto &v : adj[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    que.push(v);
                    result.push_back(v);
                }
            }
        }
        if (result.size() == n)
        {
            return result;
        }
        else
        {
            return {};
        }
    }
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites)
    {
        // topological sort return karna ha bas
        vector<int> indegree(n, 0);
        unordered_map<int, vector<int>> adj;
        for (auto &preq : prerequisites)
        {
            int a = preq[0];
            int b = preq[1];
            // b --> a
            adj[b].push_back(a);
            indegree[a]++;
        }
        //
        return topologicalSort(adj, indegree, n);
    }
};