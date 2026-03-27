/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return head;
        }
        // first of all create the new nodes after the orignal nodes
        Node *curr = head;

        while (curr)
        {
            Node *currNext = curr->next; // B
            curr->next = new Node(curr->val);
            curr->next->next = currNext;
            curr = currNext;
        }
        ///
        // second now set teh random pointers
        curr = head;
        while (curr && curr->next)
        {
            if (curr->random == NULL)
            {
                curr->next->random = NULL;
            }
            else
            {
                // now set it
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        // third now separate the lists
        curr = head;
        Node *newHead = head->next == NULL ? NULL : head->next;
        Node *newCurr = newHead;
        while (curr && newCurr)
        {
            curr->next = curr->next == NULL ? NULL : curr->next->next;
            newCurr->next = newCurr->next == NULL ? NULL : newCurr->next->next;
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};