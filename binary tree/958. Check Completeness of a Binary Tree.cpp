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
🌳 COMPLETE BINARY TREE CHECK (LeetCode 958)
═══════════════════════════════════════════════════════════════════════

📝 MEIN KAISE KIYA:
  Complete tree matlab = sare levels fully filled hote hain EXCEPT last level
  Last level LEFT-TO-RIGHT se filled hota hai

  Strategy: BFS + NULL detection
  • Queue me dono children add karo (NULL bhi)
  • Agar NULL dekha to flag set kar do
  • Agar phir se non-NULL dekha to gap hai = NOT complete
  • Agar sirf NULL hi dekhe phir to complete hai

⏱️ TIME: O(n) - har node ek baar
💾 SPACE: O(w) - w = max width

═══════════════════════════════════════════════════════════════════════
*/

class Solution
{
public:
    // 🔍 BFS se check karo k tree complete hai ya nahi
    bool isCompleteTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }

        queue<TreeNode *> q;
        q.push(root);
        bool nullNodeFound = false; // Flag: NULL dekha?

        // 🔄 Level-order traversal shuru karo
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            // Case 1: Current node NULL hai
            if (node == NULL)
            {
                // NULL dekh liya, ab sirf NULL hi should aaye
                nullNodeFound = true;
            }
            // Case 2: Current node NULL nahi hai
            else
            {
                // ⚠️ Agar NULL pehle dekha tha aur phir non-NULL dekha?
                // Yeh gap hai = NOT COMPLETE
                if (nullNodeFound == true)
                {
                    return false;
                }

                // 1️⃣ Dono children (NULL bhi) queue me dalo
                // Taakay next levels me gaps detect ho sake
                q.push(node->left);
                q.push(node->right);
            }
        }

        // ✅ Koi gap nahi mila to tree complete hai
        return true;
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