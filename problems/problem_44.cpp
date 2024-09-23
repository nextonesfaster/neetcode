// https://neetcode.io/problems/merge-k-sorted-linked-lists

#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    if (lists.empty())
      return nullptr;

    int n = lists.size();
    while (n > 1) {
      for (int i = 0; i < n / 2; i += 1)
        lists[i] = mergeLists(lists[i], lists[n - i - 1]);

      ++n /= 2; // (n+1)/2
    }

    return lists.front();
  }

  ListNode *mergeLists(ListNode *l1, ListNode *l2) {
    ListNode **merged = &l1;

    while (l2) {
      if (!(*merged) || l2->val < (*merged)->val)
        std::swap((*merged), l2);
      merged = &((*merged)->next);
    }

    return l1;
  }
};
