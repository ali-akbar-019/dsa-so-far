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
    bool isOnePresent(TreeNode *root)
    {
        if (root == NULL)
        {
            return false;
        }
        //
        if (root->val == 1)
        {
            return true;
        }
        return isOnePresent(root->left) || isOnePresent(root->right);
    }
    TreeNode *pruneTree(TreeNode *root)
    {
        //
        if (root == NULL)
        {
            return NULL;
        }
        //
        //
        if (!isOnePresent(root->left))
        {
            root->left = NULL; // ye ho jaye ga set jo waha se return huwa ha
        }
        if (!isOnePresent(root->right))
        {
            root->right = NULL; // ya to null ho ga ya to root ho ga
        }

        //
        pruneTree(root->left);
        pruneTree(root->right);
        //
        // ye ho ga return
        if (root->left == NULL && root->right == NULL && root->val == 0)
        {
            return NULL;
        }
        return root;
    }
};

//
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
    TreeNode *pruneTree(TreeNode *root)
    {
        //
        if (root == NULL)
        {
            return NULL;
        }
        //
        //

        //
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        //
        // ye ho ga return
        if (root->left == NULL && root->right == NULL && root->val == 0)
        {
            return NULL;
        }
        return root;
    }
};