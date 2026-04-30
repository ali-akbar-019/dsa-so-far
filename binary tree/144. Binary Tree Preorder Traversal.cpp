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
    // Logic: Preorder Traversal = NLR (Node -> Left -> Right)
    // Pehle root, phir left subtree, phir right subtree
    void solve(TreeNode *root, vector<int> &res)
    {
        if (root == NULL)
        {
            return;
        }

        // NLR order me add karo
        res.push_back(root->val); // Node ko pehle add karo
        solve(root->left, res);   // Phir left ko explore karo
        solve(root->right, res);  // Phir right ko explore karo
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        solve(root, result);
        return result;
    }
};