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
    int leftBottom;
    int maxDepth;
    void dfs(TreeNode *root, int currDepth)
    {
        if (root == NULL)
        {
            return;
        }
        //
        if (currDepth > maxDepth)
        {
            maxDepth = currDepth;
            leftBottom = root->val;
        }
        // left
        dfs(root->left, currDepth + 1);
        // right
        dfs(root->right, currDepth + 1);
    }
    int findBottomLeftValue(TreeNode *root)
    {
        maxDepth = -1;
        dfs(root, 0);
        return leftBottom;
    }
};