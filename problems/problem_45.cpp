// https://neetcode.io/problems/reverse-nodes-in-k-group

#include <utility>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  int s_k;

public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || k < 2)
      return head;

    s_k = k;

    ListNode *fast = head;
    ListNode *start = head;
    ListNode *prev_start = nullptr;
    int count = 0;
    while (fast) {
      count++;
      fast = fast->next;
      if (count == k) {
        auto [new_head, tail] = reverseFirstK(start);

        start->next = new_head;

        if (prev_start)
          prev_start->next = tail;
        else
          head = tail;

        prev_start = start;
        start = fast;
        count = 0;
      }
    }

    return head;
  }

  std::pair<ListNode *, ListNode *> reverseFirstK(ListNode *head) {
    // reverse this k group
    ListNode *start = head;
    ListNode *prev = nullptr;
    for (int i = 0; i < s_k; i++) {
      ListNode *tmp = start->next;
      start->next = prev;
      prev = start;
      start = tmp;
    }

    return {start, prev};
  }
};

int main() {
  Solution sol;
  ListNode *head =
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  // head->next = new ListNode(2);
  // head->next->next = new ListNode(3);
  // head->next->next->next = new ListNode(4);
  // head->next->next->next->next = new ListNode(5);
  // head->next->next->next->next->next = new ListNode(6);
  ListNode *res = sol.reverseKGroup(head, 3);
  int x = res->val + 1;
}
