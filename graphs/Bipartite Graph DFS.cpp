class Solution
{
public:
    bool checkBipartiteDFS(int curr, unordered_map<int, vector<int>> &adj, vector<int> &colors, int currColor)
    {
        colors[curr] = currColor;

        // false isi leye dke rahe har jaga q k true ki cond nahi na as such
        for (auto &v : adj[curr])
        {
            if (colors[v] == currColor)
                return false;
            if (colors[v] == -1)
            {
                // means k un assigned ha abi to assign karo is ko diff color is k neighbor se
                int vColor = 1 - currColor; // 1 huwa to zero warna 1, ! b use kar sakte the
                if (checkBipartiteDFS(v, adj, colors, vColor) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges)
    {
        // bi means k two
        // two parts me divide krana
        // two groups me
        // two colors
        // thats all bipertite
        vector<int> colors(V, -1);
        // edges se adj banate ha
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // red - 1, green - 0
        // color ko hi visited ki tara use kar lo
        for (int i = 0; i < V; i++)
        {
            if (colors[i] == -1)
            { // ab tk nahi huwa color is ko
                if (checkBipartiteDFS(i, adj, colors, 1) == false)
                    return false;
            }
        }
        return true;
    }
};