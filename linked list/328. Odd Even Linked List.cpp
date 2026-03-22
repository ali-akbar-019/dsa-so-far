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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head; // aik hi node ha ya node hi nahi ha to fir kya karna ha
        }
        ListNode *EvenStart = head->next;
        //
        ListNode *ODD = head;        // 1 - 3 - 5 - 7
        ListNode *EVEN = head->next; // 2 - 4 - 6 - 8
        while (EVEN != NULL && EVEN->next != NULL)
        {
            ODD->next = EVEN->next;
            EVEN->next = EVEN->next->next;
            ODD = ODD->next;
            EVEN = EVEN->next;
        }
        //
        ODD->next = EvenStart;
        return head;
        // 1   2     3     4      5
        // 6 - 7  -  8  -  9  -  10
        // odd even
        // odd  = even->next
        // even = even->next->next;
        // 1   2   3   4   5
        // 6   7   8   9   10
        //         o   e
    }
};