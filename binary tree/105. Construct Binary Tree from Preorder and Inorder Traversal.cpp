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
/*
═══════════════════════════════════════════════════════════════════════
🌳 PROBLEM: Preorder aur Inorder se Tree banao (LC 105)
═══════════════════════════════════════════════════════════════════════

📝 MEIN KAISE KIYA:
  • Preorder traveral ka pehla element HAMESHA root hota hai
  • Inorder me root ke left me left subtree, right me right subtree hote hain
  • Strategy: Recursion se divide karo:
    1. Preorder se root nikalo
    2. Inorder me us root ki position find karo
    3. Left wale nodes se left subtree banao
    4. Right wale nodes se right subtree banao

⏱️ TIME: O(n²) worst case (har level par linear search)
💾 SPACE: O(n) recursion stack + tree nodes

═══════════════════════════════════════════════════════════════════════
*/

class Solution
{
public:
    // Helper recursive function to build tree
    // preorder: preorder traversal array
    // inorder: inorder traversal array
    // start, end: current range in inorder array for this subtree
    // idx: current index in preorder array (reference - updates globally)
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int start, int end, int &idx)
    {
        // BASE CASE: Invalid range means no subtree exists
        if (start > end)
        {
            return NULL;
        }

        // STEP 1: First element in preorder is the ROOT (Preorder = Node-Left-Right)
        int val = preorder[idx];

        // STEP 2: Find root's position in inorder array using linear search
        int i = start;
        while (i <= end)
        {
            if (inorder[i] == val)
            {
                break;
            }
            i++;
        }

        // STEP 3: Create root node
        TreeNode *root = new TreeNode(val);
        idx++; // Move pointer to next node in preorder

        // STEP 4: Recursively build LEFT SUBTREE
        // Elements from [start to i-1] in inorder are left subtree nodes
        root->left = solve(preorder, inorder, start, i - 1, idx);

        // STEP 5: Recursively build RIGHT SUBTREE
        // Elements from [i+1 to end] in inorder are right subtree nodes
        root->right = solve(preorder, inorder, i + 1, end, idx);

        return root;
    }

    // Main function called by LeetCode
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        int idx = 0; // Index pointer for preorder array
        return solve(preorder, inorder, 0, n - 1, idx);
    }
};