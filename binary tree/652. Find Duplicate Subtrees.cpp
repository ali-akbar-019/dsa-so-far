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
    // Logic: Har subtree ko string me convert karo
    // Map me check karo - agar pehli baar dekha to count=1, dosri baar to result me add karo
    string solve(TreeNode *root, vector<TreeNode *> &res, unordered_map<string, int> &mp)
    {
        if (root == NULL)
        {
            return "N"; // Null node ka representation
        }

        // Current subtree ko string me represent karo (serialization)
        // Format: node_value,left_subtree,right_subtree
        string current_subtree = to_string(root->val) + "," + solve(root->left, res, mp) + "," + solve(root->right, res, mp);

        // Agar dusri baar dekh rahe ho ye subtree, to result me add karo
        if (mp[current_subtree] == 1)
        {
            res.push_back(root); // Duplicate subtree ka root node
        }

        // Frequency increment karo
        mp[current_subtree]++;
        return current_subtree;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        // tm string me convert kar k map me dalo and then waha check karo k already present ha ya nahi , if yes then tm node ko result me dal do else nai
        vector<TreeNode *> result;
        unordered_map<string, int> mp;
        solve(root, result, mp);
        return result;
        // dono tree ki alag alag side pe ho ge to isi waja se ye ham agar aik side pe dekh le kisi chze ko same ko dosri side pe dhonde then map me har aik k leye dosri side b entry bane gi and ham check karte rahe ge k jese hi repeat howa dosri side to ham ans me push kar le ge
    }
};