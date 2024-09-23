// https://neetcode.io/problems/valid-binary-search-tree

#include <limits>
#include <optional>

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
  bool isValidBST(TreeNode *root) { return dfs(root, std::nullopt, std::nullopt); }

  bool dfs(TreeNode *node, std::optional<int> min, std::optional<int> max) {
    if (!node)
      return true;

    return (!min.has_value() || node->val > min.value()) &&
           (!max.has_value() || node->val < max.value()) && dfs(node->left, min, node->val) &&
           dfs(node->right, node->val, max);
  }
};

int main() {
  Solution sol;
  TreeNode *root = new TreeNode(0, nullptr, new TreeNode(-1));
  sol.isValidBST(root);
}
