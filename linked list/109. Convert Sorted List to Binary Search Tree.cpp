/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
        {
            return NULL;
        }
        //
        if (!head->next)
        {
            // means k bs aik hi node ha
            TreeNode *result = new TreeNode(head->val);
            return result;
        }
        //
        //
        ListNode *slow = head;
        ListNode *slow_prev = NULL;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //
        TreeNode *root = new TreeNode(slow->val);
        if (slow_prev)
            slow_prev->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};