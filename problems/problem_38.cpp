// https://neetcode.io/problems/remove-node-from-end-of-linked-list

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *slow = dummy;
    ListNode *fast = head;

    while (n--)
      fast = fast->next;

    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }

    // slow is now n+1 steps from end
    slow->next = slow->next->next;
    return dummy->next;
  }
};
