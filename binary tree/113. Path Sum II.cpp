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
    vector<vector<int>> ans;
    void solve(TreeNode *root, int targetSum, vector<int> &temp, int sum)
    {
        if (root == NULL)
        {
            return;
        }
        // sum me add karo
        sum += root->val;
        // jab sum me dal deya ha to ans me b dal do
        temp.push_back(root->val);
        //
        // agar to root node tk pohanch gaye ha then check karo k sum kahi target sum k eq to nai ho gai
        if (root->left == NULL && root->right == NULL)
        {
            if (sum == targetSum)
            {
                ans.push_back(temp);
            }
            temp.pop_back();
            return;
        }
        //
        solve(root->left, targetSum, temp, sum);
        solve(root->right, targetSum, temp, sum);
        // back track q k agar ans na equal huwa to remove kar jao
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