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
    // Logic: Root se leaf tak path me jo numbers milte hain, unhe combine karke sum nikalo
    // Jaise path 1->2->3 = 123
    int solve(TreeNode *root, int curr)
    {
        if (root == NULL)
        {
            return 0;
        }

        // Current number ko build karo: curr*10 + node ka value
        // Example: agar curr=1 aur node=2, to next curr=12
        curr = curr * 10 + root->val;

        // Agar leaf node hai (dono children NULL hain), to ye complete number hai
        if (root->left == NULL && root->right == NULL)
        {
            return curr;
        }

        // Left aur right subtree dono ka sum nikalo
        return solve(root->left, curr) + solve(root->right, curr);
    }
    int sumNumbers(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return solve(root, 0);
    }
};