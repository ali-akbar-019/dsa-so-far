class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // dijkstras algorithm
        // first make the adj
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto &edge : times)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
        //
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(n + 1, INT_MAX);
        result[k] = 0;
        pq.push({0, k});
        while (!pq.empty())
        {
            int node = pq.top().second;
            int d = pq.top().first;

            pq.pop();
            if (d > result[node])
                continue;
            for (auto &ngbr : adj[node])
            {
                int ngbr_node = ngbr.first;
                int ngbr_dist = ngbr.second;

                if (d + ngbr_dist < result[ngbr_node])
                {
                    result[ngbr_node] = d + ngbr_dist;
                    pq.push({ngbr_dist + d, ngbr_node});
                }
            }
        }
        // ab max
        int maxi = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if (result[i] > maxi)
            {
                maxi = result[i];
            }
        }
        return maxi == INT_MAX ? -1 : maxi;
    }
};