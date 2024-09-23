// https://neetcode.io/problems/merge-two-sorted-linked-lists

#include <utility>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  // most efficient
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode **merged = &list1;

    while (list2) {
      if (!(*merged) || list2->val < (*merged)->val)
        std::swap((*merged), list2);
      merged = &((*merged)->next);
    }

    return list1;
  }

  // more efficient
  ListNode *mergeTwoListsAlt1(ListNode *list1, ListNode *list2) {
    ListNode *merged = new ListNode();
    ListNode *curr = merged;

    while (list1 && list2) {
      if (list1->val < list2->val) {
        curr->next = list1;
        list1 = list1->next;
      } else {
        curr->next = list2;
        list2 = list2->next;
      }
      curr = curr->next;
    }

    if (!list1)
      curr->next = list2;
    else
      curr->next = list1;

    return merged->next;
  }

  // efficient
  ListNode *mergeTwoListsAlt2(ListNode *list1, ListNode *list2) {
    ListNode *merged = new ListNode();
    ListNode *merged_curr = merged;

    ListNode *curr_one = list1;
    ListNode *curr_two = list2;

    while (curr_one || curr_two) {
      merged_curr->next = new ListNode();
      merged_curr = merged_curr->next;
      if (curr_one && curr_two) {
        if (curr_one->val < curr_two->val) {
          merged_curr->val = curr_one->val;
          curr_one = curr_one->next;
        } else {
          merged_curr->val = curr_two->val;
          curr_two = curr_two->next;
        }
      } else if (curr_one) {
        merged_curr->val = curr_one->val;
        curr_one = curr_one->next;
      } else {
        merged_curr->val = curr_two->val;
        curr_two = curr_two->next;
      }
    }

    return merged->next;
  }
};
