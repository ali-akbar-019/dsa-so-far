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
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        // find the middle node
        // so best method to find the middle is the slow and fast pointers
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *slowPrev = NULL;
        while (fast && fast->next)
        {
            slowPrev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        slowPrev->next = slow->next;
        delete (slow);
        return head;
    }
};