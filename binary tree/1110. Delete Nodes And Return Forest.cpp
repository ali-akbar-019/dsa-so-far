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
    // tree node le raha hu q k real wali tree me b changings karni ha
    TreeNode *solve(TreeNode *&root, vector<TreeNode *> &ans, unordered_set<int> &st)
    {
        if (root == NULL)
        {
            return NULL;
        }
        //
        //
        root->left = solve(root->left, ans, st);
        root->right = solve(root->right, ans, st);
        //
        if (st.find(root->val) != st.end())
        {
            if (root->left)
            {
                ans.push_back(root->left);
            }
            if (root->right)
            {
                ans.push_back(root->right);
            }
            // delete
            root->left = NULL;
            root->right = NULL;
            return NULL;
        }

        return root;

        //
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        //
        if (root == NULL)
        {
            return {};
        }
        //
        unordered_set<int> st;
        for (auto &it : to_delete)
        {
            st.insert(it);
        }
        //

        vector<TreeNode *> ans;
        solve(root, ans, st);
        if (st.find(root->val) == st.end())
        {
            ans.push_back(root);
        }
        return ans;
    }
};