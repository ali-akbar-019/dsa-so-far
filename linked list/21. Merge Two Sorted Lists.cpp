/*
═══════════════════════════════════════════════════════════════════════
PROBLEM: Merge Two Sorted Lists (LeetCode 21) - CLASSIC
═══════════════════════════════════════════════════════════════════════

PROBLEM STATEMENT:
  Given heads of two sorted linked lists, merge them into one sorted list.
  Example: [1→2→4] + [1→3→4] = [1→1→2→3→4→4]

ALGORITHM: Recursive Merge (shown below)
  KEY IDEA: Compare values from both lists, recursively merge smaller one.

  APPROACH:
  1. Base cases: if l1 empty return l2, if l2 empty return l1
  2. Compare current nodes: attach smaller one to merged result
  3. Recursively merge the remaining part
  4. Return the head of merged list

TIME COMPLEXITY: O(n + m) - visit each node once where n, m are lengths
SPACE COMPLEXITY: O(n + m) - recursion stack (O(1) possible iteratively)

ALTERNATIVE: Iterative approach using dummy node and a tail pointer

═══════════════════════════════════════════════════════════════════════
*/

class Solution
{
public:
    // Recursive merge of two sorted linked lists
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // BASE CASE 1: If l1 is empty, entire l2 is result
        if (!l1)
        {
            return l2;
        }

        // BASE CASE 2: If l2 is empty, entire l1 is result
        if (!l2)
        {
            return l1;
        }

        // RECURSIVE CASE: Compare and pick smaller node

        // Case: l1's value is smaller
        if (l1->val < l2->val)
        {
            // l1 will be part of result chain
            // Recursively merge l1->next with entire l2
            // This ensures we get the correct next node for l1
            l1->next = mergeTwoLists(l1->next, l2);
            return l1; // Return l1 as head for this merge
        }
        else
        {
            // l2's value is smaller or equal
            // l2 will be part of result chain
            // Recursively merge entire l1 with l2->next
            l2->next = mergeTwoLists(l1, l2->next);
            return l2; // Return l2 as head for this merge
        }
    }
};

/*
ITERATIVE APPROACH using dummy node:

  ListNode* mergeTwoListsIterative(ListNode *l1, ListNode *l2) {
      ListNode dummy(0);           // Dummy node to simplify code
      ListNode *tail = &dummy;     // Tail pointer to build list

      // Process both lists while both have nodes
      while (l1 && l2) {
          if (l1->val < l2->val) {
              tail->next = l1;     // Attach l1's node
              l1 = l1->next;       // Move l1 forward
          } else {
              tail->next = l2;     // Attach l2's node
              l2 = l2->next;       // Move l2 forward
          }
          tail = tail->next;       // Move tail forward
      }

      // Attach remaining nodes from either l1 or l2
      tail->next = l1 ? l1 : l2;

      return dummy.next;           // Return head (skip dummy)
  }

  Time: O(n+m), Space: O(1)
*/