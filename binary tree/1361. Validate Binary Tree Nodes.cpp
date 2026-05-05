class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        unordered_map<int, int> node_to_parent;
        unordered_map<int, vector<int>> adj;
        // har node ka ensure karo k just one parent ha
        for (int i = 0; i < n; i++)
        {
            int node = i;
            int leftC = leftChild[i];
            int rightC = rightChild[i];
            //
            if (leftC != -1)
            {
                if (node_to_parent.find(leftC) != node_to_parent.end())
                {
                    return false;
                }
                node_to_parent[leftC] = node;
                adj[node].push_back(leftC);
            }
            if (rightC != -1)
            {
                if (node_to_parent.find(rightC) != node_to_parent.end())
                {
                    return false;
                }
                node_to_parent[rightC] = node;
                adj[node].push_back(rightC);
            }
        }
        // find the root
        int root = -1;
        for (int i = 0; i < n; i++)
        {
            if (node_to_parent.find(i) == node_to_parent.end())
            {
                if (root != -1)
                {
                    return false;
                }
                root = i;
            }
        }
        if (root == -1)
        {
            return false;
        }
        // simple bfs karo ab
        queue<int> q;
        q.push(root);
        vector<bool> visited(n, false);
        visited[root] = true;
        int count = 1;
        while (!q.empty())
        {

            int node = q.front();
            q.pop();

            for (auto &v : adj[node])
            {
                if (visited[v])
                {
                    return false;
                }
                visited[v] = true;
                count++;
                q.push(v);
            }
        }
        return count == n;
    }
};