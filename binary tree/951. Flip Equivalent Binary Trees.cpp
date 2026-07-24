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
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        // agar dono null ha
        if (root1 == NULL && root2 == NULL)
            return true;
        // agar koi aik null ha means k mismatch ha
        if (root1 == NULL || root2 == NULL)
            return false;
        //
        // root same ha dono k
        if (root1->val == root2->val)
        {
            // ab check karo k bina flip keye same ha
            bool withoutFlip = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
            // with flip ab bas tm left ko right se compare kar lo na
            bool withFlip = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
            return withoutFlip || withFlip;
        }
        return false;
    }
};