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
    // Logic: Tree symmetric hai agar left subtree = right subtree ka mirror image
    // Left ka left == Right ka right aur Left ka right == Right ka left
    bool check(TreeNode *l, TreeNode *r)
    {
        // Agar dono NULL hain, to symmetric hai
        if (!l && !r)
        {
            return true;
        }
        // agar dono me se koi aik null ha and dosra nai ha null, to symmetric nahi
        if (!l || !r)
        {
            return false;
        }
        // agar value same na ho to symmetric nahi
        if (l->val != r->val)
        {
            return false;
        }
        // Mirror check: left ka left = right ka right, aur left ka right = right ka left
        return check(l->left, r->right) && check(l->right, r->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        return check(root->left, root->right);
    }
};