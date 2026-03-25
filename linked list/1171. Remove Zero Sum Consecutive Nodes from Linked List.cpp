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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        unordered_map<int, ListNode *> mp;
        int prefixSum = 0;
        // insert a dummy node
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        mp[0] = dummyNode;
        for (ListNode *curr = dummyNode; curr != NULL; curr = curr->next)
        {
            prefixSum += curr->val;
            mp[prefixSum] = curr;
        }
        prefixSum = 0;
        for (ListNode *curr = dummyNode; curr != NULL; curr = curr->next)
        {
            prefixSum += curr->val;
            curr->next = mp[prefixSum]->next;
        }
        return dummyNode->next;
    }
};