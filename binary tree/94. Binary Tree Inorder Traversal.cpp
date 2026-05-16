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
    vector<int> inorderTraversal(TreeNode *root)
    {
        // will be using MORIS TRAVERSAL for the inorder traversal and not the recursion method
        TreeNode *curr = root; // ye ghome ka pori tree pe
        vector<int> result;
        // jab tk current null nahi ho jata tb tk
        while (curr)
        {
            // agar to left nahi ha curr ka then is ko result me dal do
            if (curr->left == NULL)
            {
                result.push_back(curr->val);
                // and current ko kar do current ka right
                curr = curr->right;
            }
            else
            {
                TreeNode *currLeft = curr->left;
                while (currLeft->right != NULL)
                {
                    currLeft = currLeft->right;
                }
                // now its in the right most node
                currLeft->right = curr; // ta k ham current pe wapas apaye
                // store karo current ka left and us ko NULL mark kar do ta k wapas se hame
                // pora ye else wali condition me na aye
                TreeNode *temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }
        return result;
    }
};