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
    int minOpToSort(vector<int> &vec)
    {
        int n = vec.size();
        int steps = 0;
        // sorted vec lo
        vector<int> sortedVec(begin(vec), end(vec)); // copy kar lo
        sort(begin(sortedVec), end(sortedVec));
        // aik map le lo jaha pe orignal element and un ka index store kar lo
        // ta k bad me O(1) k andar unhe access kar paye
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[vec[i]] = i; // num -> index
        }
        // ab compare karo
        for (int i = 0; i < n; i++)
        {
            if (vec[i] == sortedVec[i])
                continue;
            // else we have to find the index and swap
            int index = mp[sortedVec[i]];
            mp[vec[i]] = index;
            mp[vec[index]] = i;
            swap(vec[i], vec[index]);
            steps += 1;
        }
        return steps;
    }
    int minimumOperations(TreeNode *root)
    {
        // bfs
        queue<TreeNode *> q;
        q.push(root);

        int result = 0;
        while (!q.empty())
        {
            int n = q.size();
            // har level k leye aik vec chahie jo el ko store kare
            vector<int> vec;
            while (n--)
            {
                TreeNode *node = q.front();
                q.pop();
                vec.push_back(node->val);
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            // bahar aagaye to level k sare el vec me store ho gae ho ge
            result += minOpToSort(vec);
        }
        return result;
    }
};