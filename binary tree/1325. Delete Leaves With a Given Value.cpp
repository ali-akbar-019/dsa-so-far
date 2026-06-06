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
    TreeNode *solve(TreeNode *root, int target)
    {
        if (root == NULL)
        {
            return NULL;
        }
        //
        // bhai tm left and right ka answer le ao
        root->left = solve(root->left, target);
        root->right = solve(root->right, target);
        // ab agar tmhara root hi leaf ban gaya to chek karo k agar
        // value target k equal ha to remove kar do
        if (root->left == NULL && root->right == NULL && root->val == target)
        {
            return NULL; // means k delete kar deya h
        }
        return root; // else just return the root
    }
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        // use recursion to solve this problem
        return solve(root, target);
    }
};