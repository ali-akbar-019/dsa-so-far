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
    int solve(TreeNode *root, int &moves)
    {
        if (root == NULL)
        {
            return 0;
        }
        //
        // left or right ka ans nikalo
        int left = solve(root->left, moves);
        int right = solve(root->right, moves);

        // ab moves me add karo
        moves += abs(left) + abs(right);
        // ab return karo parent ko
        return (left + right + root->val) - 1; // aik candey khud rakh lo baqi oper return kar do
    }
    int distributeCoins(TreeNode *root)
    {
        // simple sa recursion
        int moves = 0;
        solve(root, moves);
        return moves;
    }
};