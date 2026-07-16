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
    vector<int> solve(TreeNode *root, int &distance, int &goodpairs)
    {
        if (root == NULL)
        {
            return {0};
        }
        if (root->left == NULL && root->right == NULL)
        {
            return {1};
        }
        // ab tm left or right se nikalo
        vector<int> left_d = solve(root->left, distance, goodpairs);
        vector<int> right_d = solve(root->right, distance, goodpairs);
        // ab sarey pairs ka apas me check karo
        for (auto &l : left_d)
        {
            for (auto &r : right_d)
            {
                if (l != 0 && r != 0 && l + r <= distance)
                {
                    goodpairs++;
                }
            }
        }
        // ab oper 1 plus kar k bejo
        vector<int> vec;
        for (auto &l : left_d)
        {
            if (l != 0 && (l + 1) <= distance)
            {
                vec.push_back(l + 1);
            }
        }
        for (auto &r : right_d)
        {
            if (r != 0 && (r + 1) <= distance)
            {
                vec.push_back(r + 1);
            }
        }
        return vec;
    }
    int countPairs(TreeNode *root, int distance)
    {
        int goodpairs = 0;
        solve(root, distance, goodpairs);
        return goodpairs;
    }
};