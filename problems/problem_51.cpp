// https://neetcode.io/problems/subtree-of-a-binary-tree

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
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (!subRoot || !root)
      return subRoot == root;

    std::stack<TreeNode *> stack;
    stack.push(root);

    while (!stack.empty()) {
      TreeNode *node = stack.top();
      stack.pop();

      if (node->val == subRoot->val && isSameTree(node, subRoot))
        return true;

      if (node->left)
        stack.push(node->left);
      if (node->right)
        stack.push(node->right);
    }

    return false;
  }

  bool isSameTree(TreeNode *p, TreeNode *q) {
    std::stack<std::pair<TreeNode *, TreeNode *>> stack;

    stack.push({p, q});

    while (!stack.empty()) {
      auto [pn, qn] = stack.top();
      stack.pop();

      if (!pn && !qn)
        continue;
      else if (!pn || !qn || (pn->val != qn->val))
        return false;

      stack.push({pn->left, qn->left});
      stack.push({pn->right, qn->right});
    }

    return true;
  }

  bool isSubtreeRec(TreeNode *root, TreeNode *subRoot) {
    if (!root)
      return false;
    if (isSameTreeRec(root, subRoot))
      return true;
    return isSubtreeRec(root->left, subRoot) || isSubtreeRec(root->right, subRoot);
  }

  bool isSameTreeRec(TreeNode *p, TreeNode *q) {
    if (!p && !q)
      return true;
    if (!p || !q || p->val != q->val)
      return false;
    return isSameTreeRec(p->left, q->left) && isSameTreeRec(p->right, q->right);
  }
};
