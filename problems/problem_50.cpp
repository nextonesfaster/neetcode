// https://neetcode.io/problems/same-binary-tree

#include <stack>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    std::stack<TreeNode *> p_stack;
    std::stack<TreeNode *> q_stack;

    p_stack.push(p);
    q_stack.push(q);

    while (!p_stack.empty()) {
      p = p_stack.top();
      p_stack.pop();

      q = q_stack.top();
      q_stack.pop();

      if (!p && !q)
        continue;
      else if ((p && !q) || (!p && q) || (p->val != q->val))
        return false;

      p_stack.push(p->left), q_stack.push(q->left);
      p_stack.push(p->right), q_stack.push(q->right);
    }

    return true;
  }
};
