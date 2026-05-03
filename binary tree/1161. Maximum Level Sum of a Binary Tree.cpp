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
    int maxLevelSum(TreeNode *root)
    {
        int max_sum = INT_MIN;
        int ans_level = 1;
        int curr_level = 1;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            int sum = 0;
            while (n--)
            {
                TreeNode *curr = q.front();
                q.pop();
                sum += curr->val;
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            if (sum > max_sum)
            {
                max_sum = sum;
                ans_level = curr_level;
            }
            curr_level++;
        }
        return ans_level;
    }
};