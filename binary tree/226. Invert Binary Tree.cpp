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
    void solve(TreeNode *root)
    {
        //
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            return;
        }
        // ab dekhta tha k mere do children ha
        if (root->left && root->right)
        {
            // store the right temp
            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = temp;
        }
        // agar koi aik child ha
        else if (root->left || root->right)
        {
            // means koi single child ha use dosri side le k jana ha
            if (root->left)
            {
                root->right = root->left;
                root->left = NULL;
            }
            if (root->right)
            {
                root->left = root->right;
                root->right = NULL;
            }
        }
        solve(root->left);
        solve(root->right);
    }
    TreeNode *invertTree(TreeNode *root)
    {

        solve(root);
        return root;
    }
};

// working
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
    void solve(TreeNode *root)
    {
        if (root == NULL)
            return;
        swap(root->left, root->right);
        solve(root->left);
        solve(root->right);
    }
    TreeNode *invertTree(TreeNode *root)
    {
        solve(root);
        return root;
    }
};