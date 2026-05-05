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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || !head->next || k == 0)
        {
            return head;
        }
        //
        //
        // first of all point the tail to the head
        ListNode *tail = head;
        int len = 1;
        while (tail->next)
        {
            len++;
            tail = tail->next;
        }
        k = k % len; // ye multiples k leye ha , ta k ham check kare k aagar multiple h k ka
        // fir rotate ho k wapas wahi ban jaye ga isi leye krne ki zarraot nai ha
        if (k == 0)
        {
            return head;
        }
        //
        tail->next = head;
        // now find the kth node from the end
        ListNode *temp = head;
        ListNode *kthNode = NULL;
        int cnt = 1;

        while (temp)
        {
            if (cnt == (len - k))
            {
                kthNode = temp;
                break;
            }
            cnt++;
            temp = temp->next;
        }
        //
        head = kthNode->next;
        kthNode->next = NULL; // this is now the tail
        return head;
    }
};