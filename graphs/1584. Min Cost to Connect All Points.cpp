class Solution
{
public:
    typedef pair<int, int> P;
    int PrimsAlgo(unordered_map<int, vector<P> > &adj, int V)
    {
        priority_queue<P, vector<P>, greater<P> > pq;
        // visited
        vector<bool> visited(V, false);
        pq.push({0, 0});
        int sum = 0;
        while (!pq.empty())
        {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if (visited[node])
                continue;
            visited[node] = true;
            sum += wt;
            for (auto &ngbr : adj[node])
            {
                int ngbr_node = ngbr.first;
                int ngbr_wt = ngbr.second;
                if (!visited[ngbr_node])
                {
                    pq.push({ngbr_wt, ngbr_node});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int> > &points)
    {
        // Min spanning tree - PRIMS
        int V = points.size();
        unordered_map<int, vector<P> > adj;
        for (int i = 0; i < V; i++)
        {
            for (int j = i + 1; j < V; j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        return PrimsAlgo(adj, V);
    }
};