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
    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int postStart, int postEnd)
    {
        if (inStart > inEnd || postStart > postEnd)
        {
            return NULL;
        }
        //
        // last node of the postorder is the first node
        TreeNode *root = new TreeNode(postorder[postEnd]);
        // find in the inorder array
        int i = inStart;
        for (; i <= inEnd; i++)
        {
            if (inorder[i] == root->val)
            {
                break;
            }
        }
        // now
        int leftSize = i - inStart;
        int rightSize = inEnd - i;
        // left and right
        root->left = solve(inorder, postorder, inStart, i - 1, postStart, postStart + leftSize - 1);
        root->right = solve(inorder, postorder, i + 1, inEnd, postEnd - rightSize, postEnd - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int inStart = 0;
        int inEnd = inorder.size() - 1;
        int postStart = 0;
        int postEnd = postorder.size() - 1;
        return solve(inorder, postorder, inStart, inEnd, postStart, postEnd);
    }
};