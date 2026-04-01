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
    ListNode *doubleIt(ListNode *head)
    {
        if (!head)
        {
            return head;
        }

        //
        ListNode *result = new ListNode(0);
        //
        ListNode *revHead = reverseLL(head);
        //
        int carry = 0;
        ListNode *node = revHead;
        while (node)
        {
            int val = carry + (node->val * 2);
            result->val = val % 10;
            carry = val / 10;
            ListNode *newCar = new ListNode(carry);
            newCar->next = result;
            result = newCar;
            node = node->next;
        }
        return result->val == 0 ? result->next : result;
    }
};