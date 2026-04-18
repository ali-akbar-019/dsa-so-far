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
    TreeNode *add(TreeNode *root, int val, int depth, int curr)
    {
        if (root == NULL)
        {
            return NULL;
        }
        //
        if (curr == depth - 1)
        {
            // means k hame ab lagana ha
            TreeNode *rootLeft = root->left;
            TreeNode *rootRight = root->right;
            ///
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            //
            root->left->left = rootLeft;
            root->right->right = rootRight;
            return root;
        }
        //
        root->left = add(root->left, val, depth, curr + 1);
        root->right = add(root->right, val, depth, curr + 1);
        return root;
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        // agar to first pe hi add krna ha then new node banao and ye current root ko us ka left child bana do question me ea hi deaya gaya ha
        if (depth == 1)
        {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        // else
        int curr = 1;
        return add(root, val, depth, curr);
    }
};