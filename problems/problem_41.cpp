// https://neetcode.io/problems/linked-list-cycle-detection

struct Node {
  int val;
  Node *next;
  Node() : val(0), next(nullptr) {}
  Node(int x) : val(x), next(nullptr) {}
  Node(int x, Node *next) : val(x), next(next) {}
};

class Solution {
public:
  bool hasCycle(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast)
        return true;
    }

    return false;
  }
};
