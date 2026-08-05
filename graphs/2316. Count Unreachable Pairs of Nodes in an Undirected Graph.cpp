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
    void Union(int x, int y)
    {
        int x_parent = Find(x);
        int y_parent = Find(y);
        if (x_parent == y_parent)
            return;
        if (rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent;
        }
        else if (rank[y_parent] < rank[x_parent])
        {
            parent[y_parent] = x_parent;
        }
        else
        {
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        // comp bana lo
        // fir comp ka size store kar lo
        // fir tm har aik maping check karo formula res += size * (rem size - size)
        // return kar do result ko
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        //---
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            // comps bana lo
            Union(u, v);
        }
        // size nikalo har comp ka
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x = Find(i);
            mp[x]++;
        }
        // ab result nikalo
        long long res = 0;
        long long remSize = n;
        for (auto &it : mp)
        {
            long long size = it.second;
            res += size * (remSize - size);
            remSize -= size;
        }
        return res;
    }
};