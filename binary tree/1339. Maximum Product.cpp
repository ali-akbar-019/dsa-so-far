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

    // Logic: Total sum nikalo (puri tree ka)
    // Phir har node par ek cut imagine karo aur product nikalo
    // Maximum product wapas karo

    // Pehle total sum calculate karo
    long calcTotalSum(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        long leftSubtreeSum = calcTotalSum(root->left);
        long rightSubtreeSum = calcTotalSum(root->right);
        long sum = root->val + leftSubtreeSum + rightSubtreeSum;
        return sum;
    }

    // Har node par cut karo aur product calculate karo
    long calcMaxProd(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        long leftSubtreeSum = calcMaxProd(root->left);
        long rightSubtreeSum = calcMaxProd(root->right);

        // Agar is node se upar cut karo, to left part ka sum
        long s1 = root->val + leftSubtreeSum + rightSubtreeSum;

        // Right part = total - left part
        long s2 = totalSum - s1;

        // Maximum product ko track karo
        maxProd = max(maxProd, s1 * s2);
        return s1;
    }
    int maxProduct(TreeNode *root)
    {
        totalSum = calcTotalSum(root);
        calcMaxProd(root);
        return maxProd % M;
    }
};