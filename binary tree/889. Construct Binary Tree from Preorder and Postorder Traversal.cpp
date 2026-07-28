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
    TreeNode *solve(int prestart, int poststart, int preend, vector<int> &preorder, vector<int> &postorder)
    {
        if (prestart > preend)
            return NULL;
        // preorder ka first is root
        TreeNode *root = new TreeNode(preorder[prestart]);
        //
        if (prestart == preend)
        {
            return root; // aik hi node ha
        }
        // next node in the preorder is the root of the left subtree
        int nextNode = preorder[prestart + 1];
        // ise dhondo post me
        int j = 0;
        while (postorder[j] != nextNode)
        {
            j++;
        }
        int num = j - poststart + 1;
        // ab left and right
        root->left = solve(prestart + 1, poststart, prestart + num, preorder, postorder);
        root->right = solve(prestart + num + 1, j + 1, preend, preorder, postorder);
        return root;
    }
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {

        int n = preorder.size();
        // pre-> NLR
        // post->LRN
        return solve(0, 0, n - 1, preorder, postorder);
    }
};