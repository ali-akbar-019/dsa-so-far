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
    void makeGraph(TreeNode *root, TreeNode *prev, unordered_map<TreeNode *, vector<TreeNode *>> &adj,
                   unordered_set<TreeNode *> &leafNodes)
    {
        if (root == NULL)
        {
            return;
        }
        //
        if (root->left == NULL && root->right == NULL)
        {
            leafNodes.insert(root);
        }
        //
        if (prev != NULL)
        {
            adj[prev].push_back(root);
            adj[root].push_back(prev);
        }
        // left and right
        makeGraph(root->left, root, adj, leafNodes);
        makeGraph(root->right, root, adj, leafNodes);
    }
    int countPairs(TreeNode *root, int distance)
    {

        // graph bana lo
        unordered_map<TreeNode *, vector<TreeNode *>> adj;
        // for the leaf nodes
        unordered_set<TreeNode *> leafNodes;
        makeGraph(root, NULL, adj, leafNodes);

        // now the bfs
        int count = 0;
        // ab har leaf k leye dekho
        for (auto &leaf : leafNodes)
        {
            queue<TreeNode *> que;
            unordered_set<TreeNode *> visited;
            que.push(leaf);
            visited.insert(leaf);
            for (int level = 0; level <= distance; level++)
            {
                int size = que.size();
                while (size--)
                {
                    TreeNode *node = que.front();
                    que.pop();

                    if (node != leaf && leafNodes.count(node))
                    {
                        count++;
                    }
                    for (auto &ngbr : adj[node])
                    {
                        if (!visited.count(ngbr))
                        {
                            visited.insert(ngbr);
                            que.push(ngbr);
                        }
                    }
                }
            }
        }
        return count / 2;
    }
};