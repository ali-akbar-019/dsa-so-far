class Solution
{
public:
    // directed ha isi leye recursion wala chale ga
    bool dfsCycle(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &inRecursion)
    {
        visited[u] = true;
        inRecursion[u] = true;

        for (auto &v : adj[u])
        {
            if (!visited[v] && dfsCycle(adj, v, visited, inRecursion))
            {
                return true;
            }
            else if (inRecursion[v])
            {
                return true;
            }
        }
        inRecursion[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // chalo ab dfs se karte ha
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        //
        unordered_map<int, vector<int>> adj;
        for (auto &preq : prerequisites)
        {
            int a = preq[0];
            int b = preq[1];
            adj[b].push_back(a);
        }
        //
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i] && dfsCycle(adj, i, visited, inRecursion))
            {
                return false; // cz k cycle ha
            }
        }
        return true; // cyle nahi ha
    }
};