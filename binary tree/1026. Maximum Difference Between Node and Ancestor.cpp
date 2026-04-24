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
    int solve(TreeNode *root, int minv, int maxv)
    {
        if (root == NULL)
        {
            return abs(maxv - minv);
        }
        //
        // update the min and the max values
        minv = min(minv, root->val);
        maxv = max(maxv, root->val);
        // left ka ans nikalo
        int left = solve(root->left, minv, maxv);
        int right = solve(root->right, minv, maxv);
        return max(left, right);
    }
    int maxAncestorDiff(TreeNode *root)
    {
        return solve(root, root->val, root->val);
    }
};