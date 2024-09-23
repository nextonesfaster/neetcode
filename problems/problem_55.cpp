// https://neetcode.io/problems/count-good-nodes-in-binary-tree

#include <limits>
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
  int goodNodes(TreeNode *root) {
    std::stack<std::pair<TreeNode *, int>> stack;
    stack.push({root, std::numeric_limits<int>::min()}); // root is guaranteed to be not null
    int good = 0;

    while (!stack.empty()) {
      auto [node, path_max] = stack.top();
      stack.pop();

      int new_max = path_max;
      if (node->val >= path_max) {
        good++;
        new_max = node->val;
      }
      if (node->left)
        stack.push({node->left, new_max});
      if (node->right)
        stack.push({node->right, new_max});
    }

    return good;
  }

  int goodNodesRec(TreeNode *root) {
    int count = 0;
    dfs(root, std::numeric_limits<int>::min(), count);
    return count;
  }

  void dfs(TreeNode *node, int max, int &count) {
    if (!node)
      return;

    if (node->val >= max) {
      max = node->val;
      count++;
    }

    dfs(node->left, max, count);
    dfs(node->right, max, count);
  }
};

int main() {
  // root=[3,3,null,4,2]
  Solution sol;
  TreeNode *root = new TreeNode(3, new TreeNode(3, new TreeNode(4), new TreeNode(2)), nullptr);
  sol.goodNodes(root);
}
