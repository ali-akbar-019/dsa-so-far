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
    long totalSum = 0;
    long maxProd = 0;
    int M = 1e9 + 7;
    // function to calculate the total sum
    long calcTotalSum(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        //
        long leftSubtreeSum = calcTotalSum(root->left);
        long rightSubtreeSum = calcTotalSum(root->right);
        long sum = root->val + leftSubtreeSum + rightSubtreeSum;
        return sum;
    }
    // functio to find the max product
    long calcMaxProd(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        long leftSubtreeSum = calcMaxProd(root->left);
        long rightSubtreeSum = calcMaxProd(root->right);
        long s1 = root->val + leftSubtreeSum + rightSubtreeSum;
        //
        long s2 = totalSum - s1;
        maxProd = max(maxProd, s1 * s2);
        return s1; // cz we are calculating the subtree sum also for each
    }
    int maxProduct(TreeNode *root)
    {
        totalSum = calcTotalSum(root);
        calcMaxProd(root);
        return maxProd % M;
    }
};