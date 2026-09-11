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
    pair<int, int> solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return {0, 0};
        }
        //
        auto P1 = solve(root->left);  // left ka sum and us ka count k kitni nodes ha
        auto P2 = solve(root->right); // right ka sum and us ka count k kitni nodes ha

        int totalSum = P1.first + P2.first + root->val;
        int totalCount = P1.second + P2.second + 1;

        int avg = totalSum / totalCount;
        if (avg == root->val)
        {
            result += 1;
        }
        return {totalSum, totalCount};
    }
    int averageOfSubtree(TreeNode *root)
    {
        // simple sa O(n) approach use kare ge
        // format: pair ho ga jis me first value ho gi total sum and second value ho gi total count so far
        solve(root);
        return result;
    }
};