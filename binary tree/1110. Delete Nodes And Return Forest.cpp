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
    // 🔄 Recursive solve function - bottom-up approach
    // jab delete nodes ko remove karenge tab unke children separate forests ban jayenge
    TreeNode *solve(TreeNode *&root, vector<TreeNode *> &ans, unordered_set<int> &st)
    {
        if (root == NULL)
        {
            return NULL;
        }

        // 1️⃣ Pehle left subtree process karo
        root->left = solve(root->left, ans, st);
        // 2️⃣ Phir right subtree process karo
        root->right = solve(root->right, ans, st);

        // 3️⃣ Agar is node ko delete karna hai
        if (st.find(root->val) != st.end())
        {
            // Left child agar exist karay to separate forest ban jayega
            if (root->left)
            {
                ans.push_back(root->left);
            }
            // Right child agar exist karay to separate forest ban jayega
            if (root->right)
            {
                ans.push_back(root->right);
            }
            // Current node ko disconnect kar do
            root->left = NULL;
            root->right = NULL;
            return NULL; // Is node ko nahi rakhna
        }

        return root; // Is node ko rakhna hai
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        if (root == NULL)
        {
            return {};
        }

        // 🔍 Pehle delete karne wale nodes ko set me rakh do (fast lookup ke liye)
        unordered_set<int> st;
        for (auto &it : to_delete)
        {
            st.insert(it);
        }

        vector<TreeNode *> ans;
        // 🌳 Recursively process tree
        solve(root, ans, st);

        // ✅ Agar root delete nahi hona toh us ko bhi answer me add karo
        if (st.find(root->val) == st.end())
        {
            ans.push_back(root);
        }
        return ans;
    }
};