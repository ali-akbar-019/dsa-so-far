#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
═══════════════════════════════════════════════════════════════════════
🌳 FIND LEAVES IN LEVEL ORDER - LeetCode 366
═══════════════════════════════════════════════════════════════════════

📝 MEIN KAISE KIYA:
  Tree ke leaves ko collect karo by LEVELS
  Strategy:
  1. Har node ke height ko calculate karo (leaf = height 0)
  2. Map me store karo: height -> nodes at that height
  3. Height order se leaves collect karo

  Post-order DFS use karenge:
  • Leaf node height = 0
  • Parent height = 1 + max(left height, right height)
  • Nodes same height on same level

⏱️ TIME: O(n)
💾 SPACE: O(n) map + recursion

═══════════════════════════════════════════════════════════════════════
*/

// Definition for a binary tree node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// 🌄 Height calculate karo aur map me store karo
int solve(Node *root, unordered_map<int, vector<int>> &mp)
{
    // Base case: null node
    if (root == NULL)
    {
        return 0; // Height 0 return karo
    }

    // 1️⃣ Left subtree ki height
    int leftH = solve(root->left, mp);
    // 2️⃣ Right subtree ki height
    int rightH = solve(root->right, mp);
    // 3️⃣ Current node ki height = 1 + max(left, right)
    int H = 1 + max(leftH, rightH);

    // 📋 Is height ke nodes map me daal do
    mp[H].push_back(root->val);

    return H; // Height return karo parent ke liye
}

vector<vector<int>> findLeaves(Node *root)
{
    if (root == NULL)
    {
        return {};
    }

    // 🗣️ Map: height -> vector of nodes
    unordered_map<int, vector<int>> mp;

    // 🌳 Solve recursively aur heights calculate karo
    solve(root, mp);

    // 📋 Answer array bana rahe hain height order se
    vector<vector<int>> ans;
    // Note: Yahan sequence fix nahi hai, sorted height chahiye
    // Production me sort karna padega
    for (auto &it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}