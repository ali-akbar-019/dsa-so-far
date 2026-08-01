class Solution
{
public:
    bool topologicalSort(unordered_map<int, vector<int>> &adj, vector<int> &indegree, int V)
    {
        queue<int> que;
        // jis ki indegree zero ha que me dalo
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                que.push(i);
                count++;
            }
        }
        //
        while (!que.empty())
        {
            int u = que.front();
            que.pop();
            // u ko nikal deya ab jitne b is k neighbors ha un ki in degree -1 kar do
            for (auto &v : adj[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    que.push(v);
                    count++;
                }
            }
        }
        return count == V;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // graph ka question ha bhai, qk pair deye hoe ha and cond given ha k for a , b hona chahie
        //  b --> a
        // agar to cycle me phas gaye then ham nahi kar sakte ha sare courses
        //  agar to no cycle then kaam ho jaye ga dude
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for (auto &preq : prerequisites)
        {
            int a = preq[0];
            int b = preq[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        return topologicalSort(adj, indegree, numCourses);
    }
};