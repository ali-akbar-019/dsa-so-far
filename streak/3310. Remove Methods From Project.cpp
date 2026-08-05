//  wrong code
class Solution
{
public:
    void dfs(int u, vector<bool> &susp, unordered_map<int, vector<int>> &adj)
    {
        susp[u] = true;
        for (auto &v : adj[u])
        {
            if (susp[u] && susp[v])
                return;
            if (susp[u])
            {
                susp[v] = true;
            }
            dfs(v, susp, adj);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<bool> susp(n, false);
        // dfs kar lo k se har jaga
        dfs(k, susp, adj);
        //
        for (auto s : susp)
        {
            cout << s << " ";
        }
        cout << endl;
        bool isInvokedFromOutside = false;
        // ab check karo k koi aik b edge jo k un susp ha invoke kar rahi susp walo ko then susp wale sare hi ayege
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            if (susp[u] == false && susp[v] == true)
            {
                isInvokedFromOutside = true;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (isInvokedFromOutside && susp[i] == true)
            {
                ans.push_back(i);
            }
            else if (!isInvokedFromOutside && susp[i] == true)
            {
                continue;
            }
            else
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// ---
// correct code it passed
class Solution
{
public:
    void dfs(int u, vector<bool> &susp, unordered_map<int, vector<int>> &adj)
    {
        susp[u] = true;

        for (int v : adj[u])
        {
            if (susp[v])
                continue;

            dfs(v, susp, adj);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<bool> susp(n, false);
        // dfs kar lo k se har jaga
        dfs(k, susp, adj);
        //
        for (auto s : susp)
        {
            cout << s << " ";
        }
        cout << endl;
        bool isInvokedFromOutside = false;
        // ab check karo k koi aik b edge jo k un susp ha invoke kar rahi susp walo ko then susp wale sare hi ayege
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            if (susp[u] == false && susp[v] == true)
            {
                isInvokedFromOutside = true;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (isInvokedFromOutside && susp[i] == true)
            {
                ans.push_back(i);
            }
            else if (!isInvokedFromOutside && susp[i] == true)
            {
                continue;
            }
            else
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};