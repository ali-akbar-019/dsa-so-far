class Solution
{
public:
    vector<int> rank;
    vector<int> parent;
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
        else if (rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent;
        }
        else
        {
            // kisi ko b
            parent[y_parent] = x_parent;
            // rank parent ka plus b karo
            rank[x_parent] += 1;
        }
    }
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // resize karo
        rank.resize(V, 0);
        parent.resize(V); // 0,1,2,3...
        //
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
        // union karte raho
        // agar parent same agaye then cycle ha
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            if (Find(u) == Find(v))
            {
                return true;
            }
            else
            {
                Union(u, v);
            }
        }
        //

        return false;
    }
};