/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: Lowest Common Ancestor of a Binary Tree (LeetCode 236)
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  Given two nodes p and q in a binary tree, find their LOWEST COMMON ANCESTOR (LCA).
  LCA is the deepest node that is ancestor of both p and q.

ALGORITHM: Post-order DFS (Bottom-Up Approach)
  - Recursively search in left and right subtrees
  - BASE CASE: If we find p or q, return it
  - If both left and right return non-null → current node is LCA (p and q in different subtrees)
  - If only one side returns non-null → LCA is on that side (both p and q are there)

KEY INSIGHT: Post-order traversal (process children, then parent) ensures we find
the DEEPEST common ancestor.

TIME COMPLEXITY: O(n) - visit each node one time
SPACE COMPLEXITY: O(h) - recursion stack, h = height (O(n) for skewed tree)

═══════════════════════════════════════════════════════════════════════
*/

class Solution
{
public:
    // Recursive function to find Lowest Common Ancestor
    // root: current node being processed
    // p, q: two target nodes whose LCA we need to find
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // BASE CASE 1: If reach null, no node exists here
        if (root == NULL)
        {
            return NULL;
        }

        // BASE CASE 2: If current node matches p or q, return it
        // It could be the LCA (or on the path to LCA)
        if (root == p || root == q)
        {
            return root;
        }

        // STEP 1: Search in LEFT subtree for p and q (Post-order: process children first)
        TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);

        // STEP 2: Search in RIGHT subtree for p and q
        TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);

        // STEP 3: Analyze results and determine LCA

        // CASE 1: Both left and right return non-null
        // Means p is in left subtree and q is in right subtree (or vice versa)
        // Therefore current node is their LCA
        if (leftAns != NULL && rightAns != NULL)
        {
            return root;
        }

        // CASE 2: Only left returns non-null
        // Both p and q must be in left subtree (or one of them was found)
        // LCA is on the left side
        if (leftAns == NULL)
        {
            return rightAns; // Could be null or have the LCA
        }

        // CASE 3: Only right returns non-null
        // Both p and q are on the left side
        return leftAns; // LCA is already in left result
    }
};