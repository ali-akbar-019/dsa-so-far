#include <iostream>
#include <vector>
#include <algorithm>

//
// Definition for a binary tree node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int x) : val(x), left(NULL), right(NULL) {}
}
//
int solve(Node *root, unordered_map<int, vector<int>> &mp)
{
    if (root == NULL)
    {
        return 0;
    }
    //
    int leftH = solve(root->left, mp);
    int rightH = solve(root->right, mp);
    int H = 1 + max(leftH, rightH);
    mp[H].push_back(root->val);
    return H;
}

vector<vector<int>> findLeaves(Node *root)
{

    if (root == NULL)
    {
        return {};
    } //
    //
    unordered_map<int, vector<int>> mp;
    solve(root, mp);
    vector<vector<int>> ans;
    for (int &it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}