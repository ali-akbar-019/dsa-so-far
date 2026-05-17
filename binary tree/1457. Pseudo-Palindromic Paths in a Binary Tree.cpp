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
    int result = 0;
    void solve(TreeNode *root, vector<int> &count)
    {
        if (root == NULL)
        {
            return;
        }
        // current node ko count karo
        count[root->val]++;
        // agar leaf node mil gaya
        if (root->left == NULL && root->right == NULL)
        {
            // freq check karo odd ki
            int oddFreq = 0;
            for (int i = 1; i <= 9; i++)
            {
                if (count[i] % 2 != 0)
                {
                    oddFreq++;
                }
            }
            if (oddFreq <= 1)
            {
                result += 1;
            }
        }
        // left and right me call kar do
        solve(root->left, count);
        solve(root->right, count);
        // backtrack karo
        count[root->val]--;
    }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        //
        vector<int> count(10, 0); // freq k leye use kare ge is ko
        solve(root, count);
        return result;
    }
};