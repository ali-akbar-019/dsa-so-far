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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        if (!head)
        {
            return head;
        }
        // set me dal do ta k ham O(1) me dal sakey
        unordered_set<int> st(nums.begin(), nums.end());
        while (head != NULL && st.find(head->val) != st.end())
        {
            //
            ListNode *temp = head;
            head = head->next;
            // delete(temp);
        }
        //------------------------------------------------------
        ListNode *curr = head;
        while (curr && curr->next)
        {
            if (st.find(curr->next->val) != st.end())
            {
                ListNode *temp = curr->next;
                curr->next = curr->next->next;
                // delete(temp);
            }
            else
            {
                curr = curr->next;
            }
        }
        return head;
    }
};