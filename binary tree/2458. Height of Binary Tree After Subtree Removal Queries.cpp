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
    int levels[100001];
    int heights[100001];
    int levelMaxHt[100001];
    int levelSecondMaxHt[100001];
    int findHeight(TreeNode *root, int currLevel)
    {
        if (root == NULL)
            return 0;
        // level me ye node araha ha
        levels[root->val] = currLevel;
        // height update karo
        heights[root->val] = max(findHeight(root->left, currLevel + 1), findHeight(root->right, currLevel + 1)) + 1;
        // ab max ht
        if (levelMaxHt[currLevel] < heights[root->val])
        {
            levelSecondMaxHt[currLevel] = levelMaxHt[currLevel];
            levelMaxHt[currLevel] = heights[root->val];
        }
        else if (levelSecondMaxHt[currLevel] < heights[root->val])
        {
            levelSecondMaxHt[currLevel] = heights[root->val];
        }
        return heights[root->val];
    }
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        // root, level
        findHeight(root, 0);
        //
        vector<int> res;
        for (auto &node : queries)
        {
            // L + H -1
            // level
            int currNodeLevel = levels[node];
            int heightAfterRemoval = levelMaxHt[currNodeLevel] == heights[node] ? levelSecondMaxHt[currNodeLevel] : levelMaxHt[currNodeLevel];
            int ansH = currNodeLevel + heightAfterRemoval - 1;
            res.push_back(ansH);
        }
        return res;
    }
};