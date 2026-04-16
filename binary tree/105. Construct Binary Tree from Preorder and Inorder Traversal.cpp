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
PROBLEM: Construct Binary Tree from Preorder and Inorder Traversal (LC 105)
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  Given preorder and inorder traversals of a binary tree, reconstruct the actual tree.

ALGORITHM: Recursive Divide & Conquer
  - Preorder: First element is always the ROOT (Node-Left-Right order)
  - Inorder: Elements LEFT of root are in LEFT subtree, RIGHT are in RIGHT subtree
  - Strategy:
    1. Take first element from preorder as root
    2. Find this element's position in inorder
    3. Left of position = left subtree nodes, Right = right subtree nodes
    4. Recursively build left and right subtrees

TIME COMPLEXITY: O(n²) worst case (finding element position is O(n) per level)
SPACE COMPLEXITY: O(n) for recursion stack + tree nodes
OPTIMIZATION: Use HashMap for O(n log n) - store inorder positions

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