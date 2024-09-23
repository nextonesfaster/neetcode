// https://neetcode.io/problems/reorder-linked-list

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  void reorderList(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *right = slow->next;
    slow->next = nullptr; // end left half

    // reverse past midpoint
    fast = nullptr;
    while (right) {
      ListNode *next = right->next;
      right->next = fast;
      fast = right;
      right = next;
    }

    // we're just reusing the variables; slow = left, fast = right (reversed)
    slow = head;
    // interleave these lists
    while (fast) {
      ListNode *next = slow->next;
      slow->next = fast;
      fast = fast->next;
      slow->next->next = next;
      slow = next;
    }
  }
};

int main() {
  Solution sol;
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(8);
  head->next->next->next->next = new ListNode(10);
  sol.reorderList(head);
}
