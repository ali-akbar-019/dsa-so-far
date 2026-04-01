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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        // we are gonna first find a critical point
        // if we find the first then we will store its position as the firstcppos
        // we will keep checking the curr cp pos with the prev cp pos, so if we find min then we update the min
        if (!head)
        {
            return {-1, -1};
        }
        //
        ListNode *prev = head;
        ListNode *curr = head->next;
        //
        int firstCriticalPointPosition = 0;
        int i = 1;
        int previosCriticalPointPosition = 0;
        // agar to last node pe agaye fir or koi critical point ho h nai sakta cz wo aapne aagle or pechle se greater hota ha
        int minDist = INT_MAX;
        int maxDist = INT_MIN;
        while (curr->next)
        {
            if ((curr->val > prev->val && curr->val > curr->next->val) || (curr->val < prev->val && curr->val < curr->next->val))
            {
                // this is a critical point
                if (previosCriticalPointPosition == 0)
                {
                    previosCriticalPointPosition = i;
                    firstCriticalPointPosition = i;
                }
                else
                {
                    minDist = min(minDist, i - previosCriticalPointPosition);
                    previosCriticalPointPosition = i;
                }
            }
            prev = curr;
            curr = curr->next;
            i++;
        }
        //
        if (minDist == INT_MAX)
        {
            return {-1, -1};
        }
        maxDist = previosCriticalPointPosition - firstCriticalPointPosition;
        return {minDist, maxDist};
    }
};