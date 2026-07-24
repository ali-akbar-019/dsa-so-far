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
    pair<int, bool> solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return {0, true};
        }
        //
        pair<int, bool> left = solve(root->left);
        pair<int, bool> right = solve(root->right);
        //
        // ab left and right ki height achuki ha
        return {max(left.first, right.first) + 1, (left.second == false || right.second == false) ? false : abs(left.first - right.first) <= 1};
    }

    bool isBalanced(TreeNode *root)
    {

        pair<int, bool> ans = solve(root);
        return ans.second;
    }
};