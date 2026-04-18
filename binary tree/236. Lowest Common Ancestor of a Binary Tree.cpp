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
🌳 LCA (Lowest Common Ancestor) - LC 236
═══════════════════════════════════════════════════════════════════════

📝 MEIN KAISE KIYA (Post-order Bottom-Up DFS):
  • Left aur right subtree me p, q ko dhundho recursively
  • Agar dono sides se non-null aye = LCA is current node (different subtrees me hain)
  • Agar sirf ek side se aye = LCA us side me he hai
  • Post-order = children process karo phir parent (deepest LCA milta hai)

⏱️ TIME: O(n)
💾 SPACE: O(h) recursion stack

═══════════════════════════════════════════════════════════════════════
*/

class Solution
{
public:
    // 🔍 P aur Q ka LCA find karo recursively
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // Base Case 1: Null node
        if (root == NULL)
        {
            return NULL;
        }

        // Base Case 2: Agar current node p ya q hai
        // Yeh LCA ho sakta hai ya path par hai
        if (root == p || root == q)
        {
            return root;
        }

        // 🌳 Left subtree me dhundho (Post-order: pehle children, phir parent)
        TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);

        // 🌳 Right subtree me dhundho
        TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);

        // 🔌 Ab decide karo k LCA kaunsa node hai

        // Case 1: Dono sides se non-null aye
        // Matlab p left me, q right me (ya opposite)
        // To current node hi LCA hai
        if (leftAns != NULL && rightAns != NULL)
        {
            return root;
        }

        // Case 2: Sirf left side se mil gaya
        // Matlab both p aur q left side me hain (ya result in left)
        if (leftAns == NULL)
        {
            return rightAns; // Right se answer return karo (ya null)
        }

        // Case 3: Sirf right side se mil gaya
        // Matlab dono left side me hain
        return leftAns; // Left se answer return karo
    };