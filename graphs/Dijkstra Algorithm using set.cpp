class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int> > &edges, int src)
    {
        set<pair<int, int> > st;
        unordered_map<int, vector<pair<int, int> > > adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int cst = edge[2];
            adj[u].push_back({v, cst});
            adj[v].push_back({u, cst});
        }

        vector<int> result(V, INT_MAX);
        result[src] = 0;
        // insert the src
        st.insert({0, src});
        while (!st.empty())
        {
            auto it = *st.begin();
            int node = it.second;
            int d = it.first;
            st.erase(it);
            if (d > result[node])
            {
                continue;
            }
            // ab kaha kaha ja sakte
            for (auto &ngbr : adj[node])
            {

                int ngbr_node = ngbr.first;
                int ngbr_dist = ngbr.second;

                if (d + ngbr_dist < result[ngbr_node])
                {
                    result[ngbr_node] = d + ngbr_dist;
                    st.insert({d + ngbr_dist, ngbr_node});
                }
            }
        }
        return result;
    }
};