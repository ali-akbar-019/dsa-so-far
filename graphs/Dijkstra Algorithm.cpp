class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // pq me pair store karo
        // pair ko uthao
        /// check karo us se kaha kaha ja sakte and agar less dist k sath
        // ja sakte then tm pq me us ko push karo and result ko b update kar do
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int cst = edge[2];
            adj[u].push_back({v, cst});
            adj[v].push_back({u, cst});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(V, INT_MAX);
        result[src] = 0;   // src se src pe jane k leye to zero hi lage ge na
        pq.push({0, src}); // first value ki base pe sort karta
        // ab jab tk pq nahi empty hoti
        while (!pq.empty())
        {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if (d > result[node])
                continue;
            // ab nbgrs deko
            for (auto &ngbr : adj[node])
            {
                int ngbr_node = ngbr.first;
                int ngbr_cost = ngbr.second;
                if (d + ngbr_cost < result[ngbr_node])
                {
                    result[ngbr_node] = d + ngbr_cost;
                    pq.push({d + ngbr_cost, ngbr_node});
                }
            }
        }
        return result;
    }
};