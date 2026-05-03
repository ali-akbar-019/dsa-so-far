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
// this is the version of the code which is using the level order traversal to solve the problem
// its not passing all the test cases because of the overflow of the index value when we are calculating the index for the children nodes

class Solution
{
public:
    typedef unsigned long long ll;
    ll max_wid = 0;
    void solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        //
        queue<pair<TreeNode *, ll>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            // har level pe tm ye karo
            ll L = q.front().second;
            ll R = q.back().second;
            max_wid = max(max_wid, R - L + 1);
            // ab in k children ko queue me dalo
            int n = q.size();
            while (n--)
            {
                TreeNode *curr = q.front().first;
                ll idx = q.front().second;
                q.pop();
                if (curr->left)
                {
                    q.push({curr->left, idx * 2 + 1});
                }
                if (curr->right)
                {
                    q.push({curr->right, idx * 2 + 2});
                }
            }
        }
    }
    int widthOfBinaryTree(TreeNode *root)
    {
        // we would use the simple level order traversal to solve this problem
        solve(root);
        return max_wid;
    }
};
// this code passes all the test cases but it is not efficient because of the overflow of the index value when we are calculating the index for the children nodes
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
    typedef unsigned long long ll;
    ll max_wid = 0;
    void solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        //
        queue<pair<TreeNode *, ll>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            // har level pe tm ye karo
            ll base = q.front().second;
            ll L = 0;
            ll R = 0;

            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = q.front().first;
                ll idx = q.front().second - base; // this will avoid hte over flow
                q.pop();
                if (i == 0)
                    L = idx;
                if (i == n - 1)
                    R = idx;

                //
                if (curr->left)
                {
                    q.push({curr->left, idx * 2 + 1});
                }

                if (curr->right)
                {
                    q.push({curr->right, idx * 2 + 2});
                }
            }
            max_wid = max(max_wid, R - L + 1);
        }
    }
    int widthOfBinaryTree(TreeNode *root)
    {
        // we would use the simple level order traversal to solve this problem
        solve(root);
        return max_wid;
    }
};