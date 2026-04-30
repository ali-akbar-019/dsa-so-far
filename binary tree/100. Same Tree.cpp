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
    // Logic: Dono trees ko recursively compare karo
    // Agar dono nodes same ho (value aur structure dono), to true return karo
    // Otherwise false
    bool solve(TreeNode *p, TreeNode *q)
    {
        // Agar ek NULL hai aur dosra nahi, to same nahi ho sakte
        if (p == NULL && q != NULL)
        {
            return false;
        }
        if (q == NULL && p != NULL)
        {
            return false;
        }
        // Agar dono NULL hain, to poora ek same poora dosra same
        if (p == NULL && q == NULL)
        {
            return true;
        }
        // Agar values different hain, to same nahi
        if (p->val != q->val)
        {
            return false;
        }

        // Ab left aur right subtrees ko recursively check karo
        int l = solve(p->left, q->left);
        int r = solve(p->right, q->right);
        // Dono left aur right same hone chahiye
        return l && r; // both true then true else no
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return solve(p, q);
    }
};