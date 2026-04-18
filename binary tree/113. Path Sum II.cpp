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
    vector<vector<int>> ans; // 📋 Sare valid paths yahan store honge

    // 🎯 DFS + Backtracking approach
    void solve(TreeNode *root, int targetSum, vector<int> &temp, int sum)
    {
        if (root == NULL)
        {
            return;
        }

        // 1️⃣ Current node ke value ko sum me add karo
        sum += root->val;
        // Current node ko path me add karo
        temp.push_back(root->val);

        // 2️⃣ Agar leaf node pk pohach gaye toh check karo
        if (root->left == NULL && root->right == NULL)
        {
            // Agar sum match karaya toh valid path hai
            if (sum == targetSum)
            {
                ans.push_back(temp);
            }
            // Backtrack - isi path ko undo kar do
            temp.pop_back();
            return;
        }

        // 3️⃣ Left aur right dono subtree explore karo
        solve(root->left, targetSum, temp, sum);
        solve(root->right, targetSum, temp, sum);
        // Backtrack - agar match nahi hua toh is node ko remove kar do
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> temp;
        int sum = 0;
        solve(root, targetSum, temp, sum);
        return ans;
    }
};