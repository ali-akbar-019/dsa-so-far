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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
        {
            return NULL;
        }
        if (!head->next)
        {
            // means we haev jst the head
            delete (head);
            return NULL;
        }
        // simple approach is that we use the fast and slow pointer
        // we gotta move the L - n soo
        ListNode *temp = head;
        for (int i = 1; i <= n; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            ListNode *temp = head->next;
            delete (head);
            return temp;
        }
        //
        ListNode *prev = head;
        while (temp && temp->next)
        {
            prev = prev->next;
            temp = temp->next;
        }
        //
        ListNode *delNode = prev->next;
        prev->next = prev->next->next;
        delete (delNode);
        return head;
    }
};