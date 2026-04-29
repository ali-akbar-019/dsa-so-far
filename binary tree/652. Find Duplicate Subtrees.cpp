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
    // this func will conver the tree to string and check one by one k already deakha ha is ko k nahi
    string solve(TreeNode *root, vector<TreeNode *> &res, unordered_map<string, int> &mp)
    {
        if (root == NULL)
        {
            return "N";
        }
        //
        string current_subtree = to_string(root->val) + "," + solve(root->left, res, mp) + "," + solve(root->right, res, mp);
        if (mp[current_subtree] == 1)
        {
            // means we have already seen it
            res.push_back(root);
        }
        //
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