class Solution
{
public:
    typedef long long ll;
    int M = 1e9 + 7;
    ll power(int base, int exponent)
    {
        if (exponent == 0)
        {
            return 1;
        }
        //
        ll half = power(base, exponent / 2);
        // adha baqi b add karo
        ll result = (half * half) % M;
        //
        if (exponent % 2 == 1)
        {
            result = (result * base) % M;
        }
        return result;
    }
    int findDepth(unordered_map<int, vector<int>> &adj, int node, int parent)
    {
        int depth = 0;
        for (auto &ngbr : adj[node])
        {
            if (ngbr == parent)
                continue;
            depth = max(depth, findDepth(adj, ngbr, node) + 1);
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>> &edges)
    {
        // adj list
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            // undirected ha to
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // now find the depth
        int d = findDepth(adj, 1, -1); // adj list, then the node and then the parent

        //
        return power(2, d - 1);
    }
};