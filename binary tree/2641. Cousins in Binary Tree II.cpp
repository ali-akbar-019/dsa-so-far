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
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return root;
        }
        queue<TreeNode *> q;
        q.push(root);
        int levelSum = root->val;
        while (!q.empty())
        {
            //
            int n = q.size();
            int nextLevelSum = 0;
            while (n--)
            {
                TreeNode *node = q.front();
                q.pop();
                node->val = levelSum - node->val;

                // sibling sum
                int siblingSum = node->left ? node->left->val : 0;
                siblingSum += node->right ? node->right->val : 0;
                // ab update kar do nodes ki value ko
                if (node->left)
                {
                    nextLevelSum += node->left->val;
                    node->left->val = siblingSum;
                    q.push(node->left);
                }
                if (node->right)
                {
                    nextLevelSum += node->right->val;
                    node->right->val = siblingSum;
                    q.push(node->right);
                }
            }
            levelSum = nextLevelSum;
        }
        return root;
    }
};