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
        int px = Find(x);
        int py = Find(y);

        if (px == py)
            return;

        if (rank[px] > rank[py])
        {
            parent[py] = px;
        }
        else if (rank[px] < rank[py])
        {
            parent[px] = py;
        }
        else
        {
            parent[py] = px;
            rank[px]++;
        }
    }

    bool equationsPossible(vector<string> &equations)
    {
        parent.resize(26);
        rank.resize(26, 0);

        for (int i = 0; i < 26; i++)
        {
            parent[i] = i;
        }

        // Pass 1: Union all equal equations
        for (auto &eq : equations)
        {
            if (eq[1] == '=')
            {
                int a = eq[0] - 'a';
                int b = eq[3] - 'a';
                Union(a, b);
            }
        }

        // Pass 2: Check all not-equal equations
        for (auto &eq : equations)
        {
            if (eq[1] == '!')
            {
                int a = eq[0] - 'a';
                int b = eq[3] - 'a';

                if (Find(a) == Find(b))
                    return false;
            }
        }

        return true;
    }
};