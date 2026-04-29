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
    bool solve(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q != NULL)
        {
            return false;
        }
        if (q == NULL && p != NULL)
        {
            return false;
        }
        if (p == NULL && q == NULL)
        {
            return true;
        }
        if (p->val != q->val)
        {
            return false;
        }

        int l = solve(p->left, q->left);
        int r = solve(p->right, q->right);
        return l && r; // both true then true else no
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return solve(p, q);
    }
};