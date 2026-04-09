/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution
{
public:
    Node *merge2SortedLL(Node *l1, Node *l2)
    {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        //
        Node *res;
        if (l1->data < l2->data)
        {
            res = l1;
            l1->bottom = merge2SortedLL(l1->bottom, l2);
        }
        else
        {
            res = l2;
            l2->bottom = merge2SortedLL(l1, l2->bottom);
        }
        return res;
    }
    Node *flatten(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        // we will use recursion for this
        Node *head = root;
        Node *head2 = flatten(root->next);
        return merge2SortedLL(head, head2);
    }
};