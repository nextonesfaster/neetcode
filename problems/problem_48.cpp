// https://neetcode.io/problems/binary-tree-diameter

#include <queue>
#include <stack>
#include <unordered_map>

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
  int diameterOfBinaryTree(TreeNode *root) {
    int diameter = 0;
    calc_depth_and_update_diameter(root, diameter);
    return diameter;
  }

  int calc_depth_and_update_diameter(TreeNode *node, int &diameter) {
    if (!node)
      return 0;

    int left = calc_depth_and_update_diameter(node->left, diameter);
    int right = calc_depth_and_update_diameter(node->right, diameter);
    diameter = std::max(diameter, left + right);
    return std::max(left, right) + 1;
  }

  // iterative soln, DFS
  int diameterOfBinaryTreeIter(TreeNode *root) {
    if (!root)
      return 0;

    int diameter = 0;

    std::stack<TreeNode *> stack;
    stack.push(root);

    std::unordered_map<TreeNode *, int> height_map;

    while (!stack.empty()) {
      TreeNode *node = stack.top();

      if (node->left && height_map.count(node->left) == 0)
        stack.push(node->left);
      else if (node->right && height_map.count(node->right) == 0)
        stack.push(node->right);
      else {
        stack.pop();
        int left = height_map.count(node->left) != 0 ? height_map[node->left] : 0;
        int right = height_map.count(node->right) != 0 ? height_map[node->right] : 0;
        diameter = std::max(diameter, left + right);
        height_map[node] = std::max(left, right) + 1;
      }
    }

    return diameter;
  }
};
