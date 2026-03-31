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
    ListNode *reverseLL(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        //
        ListNode *last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return;
        }
        // ab
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        //

        // ab reverse kar do second half ko
        ListNode *rev = reverseLL(slow);
        ListNode *curr = head;
        while (rev->next != NULL)
        {
            ListNode *tempCurrNext = curr->next;
            curr->next = rev;
            ListNode *tempRevNext = rev->next;
            rev->next = tempCurrNext;

            //
            curr = tempCurrNext;
            rev = tempRevNext;
        }
    }
};