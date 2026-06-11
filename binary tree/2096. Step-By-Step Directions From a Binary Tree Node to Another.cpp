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
    TreeNode *lowestCommonAncestorBinaryTree(TreeNode *root, int src, int dest)
    {
        if (root == NULL)
        {
            return NULL;
        }
        // ab tm deko k tmhe src ya destination me se koi aik mila ha
        if (root->val == src || root->val == dest)
        {
            // bhai tm ise return kar do
            return root;
        }
        TreeNode *l = lowestCommonAncestorBinaryTree(root->left, src, dest);
        TreeNode *r = lowestCommonAncestorBinaryTree(root->right, src, dest);
        // agar to dono mil gaye left and right
        if (l && r)
        {
            return root; // means ye tmhara lowest common ancistor ha
        }
        return l ? l : r;
    }
    bool findPath(TreeNode *LCA, int target, string &path)
    {
        if (LCA == NULL)
        {
            return false;
        }
        // agar to target mil gaya to true return kar do
        if (LCA->val == target)
            return true;
        // ab tm check karo left and right me ja k
        path.push_back('L');
        if (findPath(LCA->left, target, path))
        {
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if (findPath(LCA->right, target, path))
        {
            return true;
        }
        path.pop_back();
        // agar to kahi se b path nahi mila to bas false return kar do
        return false;
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        // pehle hame LCA chahie
        TreeNode *LCA = lowestCommonAncestorBinaryTree(root, startValue, destValue);
        //
        string LCAToSrc = "";
        string LCAToDest = "";
        //--
        findPath(LCA, startValue, LCAToSrc);
        findPath(LCA, destValue, LCAToDest);
        //--
        string ans = "";
        // abi jo src tk ka ha path us ko just up up kar do q k wo to neche se oper gaya ho ga na
        for (int i = 0; i < LCAToSrc.length(); i++)
        {
            ans.push_back('U');
        }
        // baqi ka path dal do wese hi
        ans += LCAToDest;
        return ans;
    }
};