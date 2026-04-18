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
    bool solve(TreeNode *root, int ts, int cs)
    {
        if (root == NULL)
        {
            return false;
        }
        //
        cs += root->val;
        // agar ham pohanch gaye ha leaf node pe to check karo sum
        if (root->left == NULL && root->right == NULL)
        {
            if (ts == cs)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool leftSum = solve(root->left, ts, cs);
        bool rightSum = solve(root->right, ts, cs);
        return leftSum || rightSum;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {

        if (root == NULL)
        {
            return false;
        }
        return solve(root, targetSum, 0);
    }
};