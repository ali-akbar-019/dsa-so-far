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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // base conditions
        if (!head || !head->next)
        {
            return head;
        }
        // now make a dummy node cz the head can also change
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        //
        // find the prev
        ListNode *prev = dummy;
        for (int i = 1; i < left; i++)
        {
            prev = prev->next;
        }

        ListNode *curr = prev->next != NULL ? prev->next : NULL;
        // now we gotta do the steps that i wrote on the copy right - left times
        for (int i = 1; i <= right - left; i++)
        {
            ListNode *temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
        }
        return dummy->next;
    }
};