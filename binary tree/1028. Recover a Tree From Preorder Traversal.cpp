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
    int n;
    TreeNode *solve(string &traversal, int depth, int &i)
    {
        if (i >= n)
            return NULL;
        // dash
        int j = i;

        while (j < n && traversal[j] == '-')
        {
            j++;
        }
        int dash = j - i;
        //
        if (dash != depth)
            return NULL;
        i += dash;
        // form the number
        int num = 0;
        while (i < n && isdigit(traversal[i]))
        {
            num = num * 10 + (traversal[i] - '0');
            i++;
        }
        //
        TreeNode *root = new TreeNode(num);
        root->left = solve(traversal, depth + 1, i);
        root->right = solve(traversal, depth + 1, i);
        return root;
    }
    TreeNode *recoverFromPreorder(string traversal)
    {
        n = traversal.length();
        // root , string , depth, index
        int i = 0;
        return solve(traversal, 0, i);
    }
};