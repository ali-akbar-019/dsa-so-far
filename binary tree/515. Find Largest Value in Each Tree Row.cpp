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
    vector<int> largestValues(TreeNode *root)
    {
        // edge case
        if (root == NULL)
        {
            return {};
        }
        // using bfs
        queue<TreeNode *> q;
        q.push(root);
        vector<int> result;
        while (!q.empty())
        {
            int n = q.size();
            // har level k leye
            int maxEl = INT_MIN;
            while (n--)
            {
                TreeNode *node = q.front();
                q.pop();
                maxEl = max(maxEl, node->val);
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            result.push_back(maxEl);
        }
        return result;
    }
};
// DFS APPROACH
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
    vector<int> result;
    void DFS(TreeNode *root, int depth)
    {
        if (root == NULL)
        {
            return;
        }
        //
        if (depth == result.size())
        {
            // means ham first time aye ha is depth pe
            result.push_back(root->val);
        }
        else
        {
            // ham pehle b agaye ha
            result[depth] = max(result[depth], root->val);
        }
        // ab left and right me chale jao
        DFS(root->left, depth + 1);
        DFS(root->right, depth + 1);
    }
    vector<int> largestValues(TreeNode *root)
    {
        // using DFS
        // format: current node and the depth
        DFS(root, 0);
        return result;
    }
};