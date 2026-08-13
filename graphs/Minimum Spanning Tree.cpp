class Solution
{
public:
    typedef pair<int, int> P;
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<P>> adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        int sum = 0;
        vector<bool> visited(V, false);
        while (!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (visited[node])
                continue;
            visited[node] = true;
            sum += wt;
            // ab dekhna k ham kaha kaha ja sakte
            for (auto &ngbr : adj[node])
            {
                int ngbr_node = ngbr.first;
                int ngbr_wt = ngbr.second;
                if (visited[ngbr_node] == false)
                {
                    pq.push({ngbr_wt, ngbr_node});
                }
            }
        }
        return sum;
    }
};