/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    unordered_map<TreeNode *, TreeNode *> parents;
    vector<int> res;
    void buildParents(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left)
            {
                parents[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right)
            {
                parents[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    void solve(TreeNode *target, int k)
    {
        if (target == NULL)
        {
            return;
        }
        //
        queue<TreeNode *> q;
        q.push(target);
        unordered_set<int> visited;
        visited.insert(target->val);
        while (!q.empty())
        {
            if (k == 0)
            {
                break;
            }
            //
            int n = q.size();
            while (n--)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left && !visited.count(curr->left->val))
                {
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }
                if (curr->right && !visited.count(curr->right->val))
                {
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }
                if (parents.count(curr) && !visited.count(parents[curr]->val))
                {
                    q.push(parents[curr]);
                    visited.insert(parents[curr]->val);
                }
            }
            k--;
        }
        while (!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {

        buildParents(root); // parents sare define kar lo
        solve(target, k);
        return res;
    }
};