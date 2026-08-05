class Solution
{
public:
    vector<int> parent;
    vector<int> rank;

    // this is Find by path compression
    int Find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = Find(parent[x]);
    }
    void Union(int x, int y)
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
            rank[y_parent] += 1;
        }
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        // DSU se banao
        // COMP - 1 ans ho ga
        // and min edges jo sab ko connect kare are n - 1
        int e = connections.size();
        if (e < n - 1)
        {
            return -1;
        }

        // DSU lagao
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        int comp = n;
        for (auto &edge : connections)
        {
            int u = edge[0];
            int v = edge[1];
            if (Find(u) == Find(v))
                continue; // already union ho gaye ha
            Union(u, v);
            comp -= 1;
        }
        return comp - 1; // cz two comps ko connect krne k leye aik edge chahie, same applies for all
    }
};