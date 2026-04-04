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
    string tree2str(TreeNode *root)
    {
        // simple recursion yar - DRY RUN ON COPY , jab bigli ajaye lol.
        if (root == NULL)
        {
            return "";
        }
        //
        string result = to_string(root->val); // ye ha first one ab is ki left and right b chhaie
        if (root->left == NULL && root->right == NULL)
        {
            return result;
        }
        //
        string LEFT = tree2str(root->left);
        string RIGHT = tree2str(root->right);

        if (root->left == NULL)
        {
            return result + "()" + '(' + RIGHT + ')';
        }
        if (root->right == NULL)
        {
            return result + '(' + LEFT + ')';
        }
        //

        return result + '(' + LEFT + ')' + '(' + RIGHT + ')';
    }
};