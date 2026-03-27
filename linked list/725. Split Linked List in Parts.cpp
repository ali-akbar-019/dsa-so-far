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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        // first find the length of the linked list
        int count = 0;
        ListNode *curr = head;
        while (curr)
        {
            count++;
            curr = curr->next;
        }
        //--- now -- we have the length
        // nodesPerEachBucket
        int nodesPerEach = count / k;
        int extraNodes = count % k;
        //
        vector<ListNode *> result(k, NULL);
        curr = head;
        ListNode *prev = NULL;
        for (int i = 0; i < k; i++)
        {
            result[i] = curr;
            for (int count = 1; curr && count <= nodesPerEach + (extraNodes > 0 ? 1 : 0); count++)
            {
                prev = curr;
                curr = curr->next;
            }
            if (prev)
                prev->next = NULL;
            if (extraNodes > 0)
                extraNodes--;
        }
        return result;
    }
};