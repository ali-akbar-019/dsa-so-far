/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void makeGraph(unordered_map<int, vector<int>> &adj, TreeNode *curr, int parent)
    {
        if (curr == NULL)
        {
            return;
        }
        //
        if (parent != -1)
        {
            // add to the adj
            adj[curr->val].push_back(parent);
        }
        if (curr->left)
        {
            adj[curr->val].push_back(curr->left->val);
        }
        if (curr->right)
        {
            adj[curr->val].push_back(curr->right->val);
        }
        // call in the left and the right
        makeGraph(adj, curr->left, curr->val);
        makeGraph(adj, curr->right, curr->val);
    }
    int amountOfTime(TreeNode *root, int start)
    {
        // 1. make an undirected graph from the tree
        // 2. use bfs
        // 3. return mins - 1
        unordered_map<int, vector<int>> adj;
        makeGraph(adj, root, -1);
        // now the BFS
        unordered_set<int> visited;
        visited.insert(start);
        queue<int> q;
        q.push(start);
        int mins = 0;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                int node = q.front();
                q.pop();
                // in k bacho ko dalo
                for (auto &neighbor : adj[node])
                {
                    if (visited.find(neighbor) == visited.end())
                    {
                        // means not yet visited
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
            mins++;
        }
        return mins - 1;
    }
};

// DFS HEIGHT METHOD
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int time = 0;
    int DFSHeightMethod(TreeNode *root, int start)
    {
        if (root == NULL)
        {
            return 0;
        }
        //
        // bhaiya tm left or right height nikal lo
        int LSH = DFSHeightMethod(root->left, start);
        int RSH = DFSHeightMethod(root->right, start);
        // check karo k start pe pohanch gaye ham?
        if (root->val == start)
        {
            time = max(LSH, RSH); // neche ka apna max height bej do
            return -1;
        }
        else if (LSH >= 0 && RSH >= 0)
        {
            return max(LSH, RSH) + 1; // simple height calculation wala formula ha
        }
        else
        {
            // koi aik negative ho ga
            int d = abs(LSH) + abs(RSH);
            time = max(time, d);
            return min(LSH, RSH) - 1; // aik or -1 dal do ta k wo ad ho jaye pechle minus me and return kar do
        }
        // ye case nahi reach ho ga wese b
        return 0;
    }
    int amountOfTime(TreeNode *root, int start)
    {
        // doing it with the DFS
        DFSHeightMethod(root, start);
        return time;
    }
};