class Solution
{
public:
    vector<int> parent;
    vector<int> rank;
    int Find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = Find(parent[x]);
    }
    int Union(int x, int y)
    {
        int x_parent = Find(x);
        int y_parent = Find(y);
        if (rank[x_parent] > rank[y_parent])
        {
            parent[y_parent] = x_parent;
        }
        else if (rank[y_parent] > rank[x_parent])
        {
            parent[x_parent] = y_parent;
        }
        else
        {
            parent[x_parent] = y_parent;
        }
    }
    int KruskalAlgo(vector<vector<int> > &edges)
    {

        // har aik pair check karo
        int sum = 0;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            int u_parent = Find(u);
            int v_parent = Find(v);

            if (u_parent != v_parent)
            {
                Union(u, v);
                sum += wt;
            }
        }
        return sum;
    }
    int spanningTree(int V, vector<vector<int> > &edges)
    {
        // using kruskal algorithm
        parent.resize(V);
        rank.resize(V, 0);
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
        auto comparitor = [&](vector<int> x, vector<int> y)
        {
            return x[2] < y[2];
        };
        sort(begin(edges), end(edges), comparitor);

        // ab kruskal ko call karo
        return KruskalAlgo(edges);
    }
};