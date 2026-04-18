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
    // 🔍 Check karo k subtree me 1 kahin hai ya nahi
    bool isOnePresent(TreeNode *root)
    {
        if (root == NULL)
        {
            return false;
        }
        // Agar current node 1 hai toh true
        if (root->val == 1)
        {
            return true;
        }
        // Left ya right me se kahin 1 hai?
        return isOnePresent(root->left) || isOnePresent(root->right);
    }

    // ✂️ Pruning: sare zeros ko cut karo jo 1 se connected nahi hain
    TreeNode *pruneTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        // 1️⃣ Agar left subtree me 1 nahi hai toh cut kar do
        if (!isOnePresent(root->left))
        {
            root->left = NULL;
        }
        // 2️⃣ Agar right subtree me 1 nahi hai toh cut kar do
        if (!isOnePresent(root->right))
        {
            root->right = NULL;
        }

        // 3️⃣ Recursively dono subtrees ko prune karo
        pruneTree(root->left);
        pruneTree(root->right);

        // 4️⃣ Agar current node leaf hai aur value 0 hai toh is ko bhi remove karo
        if (root->left == NULL && root->right == NULL && root->val == 0)
        {
            return NULL;
        }
        return root;
    }
};

/*
═══════════════════════════════════════════════════════════════════════
🎯 OPTIMIZED APPROACH - Ek hi pass me pruning
═══════════════════════════════════════════════════════════════════════

Yeh approach post-order DFS use karta hai. Bottom-up jane se pata chal jata hai
k kaunsi subtree me 1 hai ya nahi, phir directly decision le sakte hain.
*/

class Solution
{
public:
    // ⚡ Optimized pruning - ek hi recursion me hote hai decision
    TreeNode *pruneTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        // 1️⃣ Pehle left subtree ko prune karo
        root->left = pruneTree(root->left);
        // 2️⃣ Phir right subtree ko prune karo
        root->right = pruneTree(root->right);

        // 3️⃣ Ab check karo - agar ye node leaf hai aur 0 hai toh remove kar do
        if (root->left == NULL && root->right == NULL && root->val == 0)
        {
            return NULL;
        }
        return root; // Otherwise yeh node rakhna hai
    }
};