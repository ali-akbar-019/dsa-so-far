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
    unordered_map<int, int> mp;
    int maxDepth;
    void findDepth(TreeNode *root, int depth)
    {
        if (root == NULL)
        {
            return;
        }
        mp[root->val] = depth;
        maxDepth = max(maxDepth, depth);
        // left
        findDepth(root->left, depth + 1);
        // right
        findDepth(root->right, depth + 1);
    }
    TreeNode *solve(TreeNode *root)
    {
        if (root == NULL || mp[root->val] == maxDepth)
        {
            return root;
        }
        TreeNode *left = solve(root->left);
        TreeNode *right = solve(root->right);
        if (left && right)
            return root;
        return left ? left : right;
    }
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        // find the depth
        maxDepth = INT_MIN;
        findDepth(root, 0);
        // now lca
        return solve(root);
    }
};