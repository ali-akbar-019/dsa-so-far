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
    int maxPath = 0;
    void solve(TreeNode *root, int step, bool goLeft)
    {
        if (root == NULL)
        {
            return;
        }
        maxPath = max(maxPath, step);
        if (goLeft)
        {
            solve(root->left, step + 1, false);
            solve(root->right, 1, true);
        }
        else
        {
            solve(root->left, 1, false);
            solve(root->right, step + 1, true);
        }
    }
    int longestZigZag(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        solve(root, 0, true);
        solve(root, 0, false);
        return maxPath;
    }
};