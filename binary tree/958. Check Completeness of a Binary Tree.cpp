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
PROBLEM: Check Completeness of a Binary Tree (LeetCode 958)
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  A COMPLETE BINARY TREE has all levels fully filled except possibly the last level,
  which is filled from LEFT TO RIGHT. Determine if given tree is complete.

ALGORITHM: Level-Order BFS with NULL Detection
  - Use queue for level-order traversal
  - Push BOTH children (including NULLs) to detect gaps
  - Once we see a NULL, if we find any non-NULL after it → NOT complete
  - This captures gaps in last level

TIME COMPLEXITY: O(n) - visit each node once
SPACE COMPLEXITY: O(w) - w = max width at any level

KEY INSIGHT: If tree is complete, once NULLs appear, only NULLs should follow.

═══════════════════════════════════════════════════════════════════════
*/

class Solution
{
public:
    // Check if binary tree is complete using Level-Order BFS
    bool isCompleteTree(TreeNode *root)
    {
        // EDGE CASE: Empty tree is complete
        if (root == NULL)
        {
            return true;
        }

        queue<TreeNode *> q; // Queue for BFS
        q.push(root);
        bool nullNodeFound = false; // Flag: have we started seeing NULLs?

        // STEP 1: Process all nodes in queue (level-order traversal)
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            // CASE 1: Current node is NULL
            if (node == NULL)
            {
                // Mark that we've encountered a NULL (gap/end of level starting)
                nullNodeFound = true;
            }
            // CASE 2: Current node is NOT NULL
            else
            {
                // If we've already seen NULL but now found non-NULL node
                // This means there's a GAP in the tree
                if (nullNodeFound == true)
                {
                    return false; // NOT COMPLETE - gap found
                }

                // Add both children to queue (including NULLs)
                // This allows us to detect any gaps in next levels
                q.push(node->left);
                q.push(node->right);
            }
        }

        // STEP 2: If we exit loop without finding gaps, tree is complete
        return true; // COMPLETE
    }
};

/*
ALTERNATIVE DFS APPROACH:

  In a complete binary tree, nodes can be indexed from 1 to n:
  - Root at index 1
  - Node i has left child at 2*i, right child at 2*i + 1

  Algorithm:
    1. Count total nodes
    2. For each node, verify its index ≤ total_nodes
    3. If any index > total_nodes, not complete
*/