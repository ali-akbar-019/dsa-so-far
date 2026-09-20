class Solution
{
public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        // heir holzers algorithm
        // indeg - outdeg == 1 then last node
        // outdeg - indeg == 1 then its the starting node
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;
        //
        for (auto &edge : pairs)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            // u -- > v
            outdegree[u]++;
            indegree[v]++;
        }
        //
        // find the starting point
        int startNode = pairs[0][0];
        for (auto &it : adj)
        {
            int node = it.first;
            if (outdegree[node] - indegree[node] == 1)
            {
                startNode = node;
                break;
            }
        }
        // ab hamare pass start point ha to ab hame start se bfs krna ha heirholzer yahi kehta ha
        stack<int> st;
        st.push(startNode);
        vector<int> eulerPath;
        while (!st.empty())
        {
            int node = st.top();
            if (!adj[node].empty())
            {
                int nextNode = adj[node].back();
                adj[node].pop_back();
                st.push(nextNode);
            }
            else
            {
                // sare neigbors ho gaye discover
                eulerPath.push_back(node);
                st.pop();
            }
        }
        // ab jab pop krte krte ao ge to euler path hame reverse me mile ga end se start tk
        reverse(begin(eulerPath), end(eulerPath));
        // ab pairs banao jesa output chahie
        vector<vector<int>> ans;
        for (int i = 0; i < eulerPath.size() - 1; i++)
        {
            ans.push_back({eulerPath[i], eulerPath[i + 1]});
        }
        return ans;
    }
};