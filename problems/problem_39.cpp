#include <iostream>

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;

        Node *curr = head;
        while (curr)
        {
            Node *next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = next;
        }

        curr = head;
        while (curr)
        {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        curr = head;
        Node *new_head = head->next;
        while (curr)
        {
            Node *next = curr->next->next;

            if (next)
                curr->next->next = next->next;

            curr->next = next;
            curr = next;
        }

        return new_head;
    }
};

int main()
{
    Solution sol;

    Node *head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);

    head->random = head->next->next;       // 0 -> 2
    head->next->random = head->next->next; // 1 -> 2
    head->next->next->next->random = head; // 3 -> 0

    Node *copy = sol.copyRandomList(head);
    while (copy)
    {
        std::cout << "v: " << copy->val << " r: " << (copy->random ? copy->random->val : -1) << ", ";
        copy = copy->next;
    }
    std::cout << std::endl;
}
