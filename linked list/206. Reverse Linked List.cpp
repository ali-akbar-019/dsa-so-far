/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: Reverse Linked List (LeetCode 206) - CLASSIC
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  Given head of a singly linked list, reverse it and return new head.
  Example: 1→2→3→NULL becomes 3→2→1→NULL

ALGORITHM: Recursive Reversal (shown below)
  KEY IDEA: Recursively reverse list from current node onwards,
  then point child back to parent.

  APPROACH:
  1. Base case: if no node or single node, return as is
  2. Recursively reverse rest of list
  3. Make next node point back to current
  4. Break forward link to form new end of list
  5. Return tail of reversed list

TIME COMPLEXITY: O(n) - visit each node once
SPACE COMPLEXITY: O(n) - recursion call stack (can do O(1) with iteration)

ALTERNATIVE: Iterative version using three pointers (prev, curr, next)

═══════════════════════════════════════════════════════════════════════
*/

class Solution
{
public:
    // Recursive approach to reverse linked list
    ListNode *reverseList(ListNode *head)
    {
        // BASE CASE: If list is empty or only 1 node, already reversed
        if (!head || !head->next)
        {
            return head;
        }

        // RECURSIVE CASE:
        // Step 1: Recursively reverse the rest of list
        // `last` will be the new head (tail of original list)
        ListNode *last = reverseList(head->next);

        // Step 2: current head->next is the node we just processed
        // Make that node point back to current node
        // This reverses the link: was A→B, now A←B
        head->next->next = head;

        // Step 3: Break the forward link to create new end
        // This prevents cycles: A should point to NULL after reversal
        head->next = NULL;

        // Step 4: Return the new head (which is the tail of original)
        return last;
    }
};

/*
ITERATIVE APPROACH (O(1) space):

  ListNode* reverseListIterative(ListNode *head) {
      ListNode *prev = NULL;      // Points to previous node
      ListNode *curr = head;      // Current node

      while (curr) {
          ListNode *next = curr->next; // Save next before breaking link
          curr->next = prev;           // Reverse the link
          prev = curr;                 // Move prev forward
          curr = next;                 // Move curr forward
      }

      return prev; // New head
  }

  Time: O(n), Space: O(1)
*/