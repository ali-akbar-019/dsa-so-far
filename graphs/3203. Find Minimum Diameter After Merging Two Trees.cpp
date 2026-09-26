class Solution
{
public:
    unordered_map<int, vector<int> > buildAdj(vector<vector<int> > &edges)
    {
        unordered_map<int, vector<int> > adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    pair<int, int> findFarthestNode(unordered_map<int, vector<int> > &adj, int src)
    {
        unordered_map<int, bool> visited;
        queue<int> q;
        q.push(src);
        visited[src] = true;
        int farthestNode = src;
        int distance = 0;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                int node = q.front();
                q.pop();
                farthestNode = node;
                for (auto &ngbr : adj[node])
                {
                    if (visited[ngbr])
                        continue;
                    q.push(ngbr);
                    visited[ngbr] = true;
                }
            }
            // ab deko k kahi empty to nahi ho gaya warna tm ++ kar do level ko
            if (!q.empty())
            {
                distance += 1;
            }
        }
        return {farthestNode, distance};
    }
    int findDiameter(unordered_map<int, vector<int> > &adj)
    {
        // random node select kar lo koi
        int randomNode = 0;
        // step 1 : random node se farthest  node ko dhondo
        auto [farthest, distance] = findFarthestNode(adj, randomNode);
        // step 2: ab ye jo oper farthest node mila h ye diameter ka aik end ha
        // find the second end same
        auto [otherEnd, diameter] = findFarthestNode(adj, farthest);
        // return kar do diameter ko
        return diameter;
    }
    int minimumDiameterAfterMerge(vector<vector<int> > &edges1, vector<vector<int> > &edges2)
    {
        // agar connect kare am to ese connect ho ga k diameter us me min bane
        //  like mid to mid connect kar do to fir oper se nodes deko ya neche se same length bane gi
        // and diameter its self hota ha longest distance between two nodes in the graph
        //  to bs fir ham diameter ko return kar de ge
        // first jo ha tree us k diameter ko d1 , second ko d2 and combines ko combined diamter kahe ge
        // in ka max return karna ho ga hame.
        unordered_map<int, vector<int> > adj1 = buildAdj(edges1);
        unordered_map<int, vector<int> > adj2 = buildAdj(edges2);

        // diameter
        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);
        int d3 = ((d1 + 1) / 2) + ((d2 + 1) / 2) + 1; // mid se connect krne k bad ka diameter, +1 jo connect keya edge ha
        return max({d1, d2, d3});
    }
};