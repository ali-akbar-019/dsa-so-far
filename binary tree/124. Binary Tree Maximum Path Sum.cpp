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
        // aik kaam karo tm sum nikal lao left and right ka
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);
        // ab tm ye teen conditions deko
        // ya to tmhe neeche hi acha sa answer mil gaya ha to tmhe ise return karne ki b need nahi ha
        int neeche_hi_acha = root->val + leftSum + rightSum;
        // neche left side ya right side me se kisi aik se tmeh acha answer araha ha q k dosri side pe -ve values ho gi
        int kisi_aik_side = max(leftSum, rightSum) + root->val;
        // root ki hi value theek ha bs baqi ki nahi theek
        int sirf_root_acha = root->val;
        maxSum = max({maxSum, neeche_hi_acha, kisi_aik_side, sirf_root_acha});

        return max(sirf_root_acha, kisi_aik_side); // neche solution acha ham ne pakka pakka maan lea the to us ko oper return karne ki zarorat nahi q k fir oper b explore ho ga.
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