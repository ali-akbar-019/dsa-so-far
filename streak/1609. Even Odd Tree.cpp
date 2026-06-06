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
    bool isEvenOddTree(TreeNode *root)
    {
        // using simple bfs
        queue<TreeNode *> q;
        q.push(root);
        bool is_even = true;

        while (!q.empty())
        {

            int n = q.size(); // level ka size
            int prev_el = is_even ? INT_MIN : INT_MAX;
            //
            while (n--)
            {
                TreeNode *node = q.front();
                q.pop();

                // now check for the even and odd levels
                if (is_even && (node->val % 2 == 0 || node->val <= prev_el))
                {
                    return false;
                }
                if (!is_even && (node->val % 2 != 0 || node->val >= prev_el))
                {
                    return false;
                }
                // update the prev
                prev_el = node->val;
                // now add the left and right child
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            // level change kar do
            is_even = !is_even;
        }
        return true;
    }
};