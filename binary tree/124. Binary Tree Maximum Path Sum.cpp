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
    int maxSum = INT_MIN;
    // simple si story
    int solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        // Recursively left aur right subtree ka max sum nikalo
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        // 4 possibilities hain path ke liye:
        // 1. Left aur right dono ko include karo
        int neeche_hi_acha = root->val + leftSum + rightSum;

        // 2. Left ya right me se koi aik le lo + current node (negative avoid karne ke liye)
        int kisi_aik_side = max(leftSum, rightSum) + root->val;

        // 3. Sirf current node hi lo
        int sirf_root_acha = root->val;

        // Global maximum ko update karo
        maxSum = max({maxSum, neeche_hi_acha, kisi_aik_side, sirf_root_acha});

        // Return karo sirf wo path jo oper jaega (not both sides, only one side + current)
        return max(sirf_root_acha, kisi_aik_side);
    }
    int maxPathSum(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        solve(root);
        return maxSum;
    }
};