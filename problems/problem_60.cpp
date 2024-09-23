// https://neetcode.io/problems/serialize-and-deserialize-binary-tree

#include <iostream>
#include <optional>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

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

class Codec {
public:
  // Encodes a tree to a single string.
  std::string serialize(TreeNode *root) {
    std::queue<TreeNode *> queue;
    queue.push(root);

    std::vector<std::optional<int>> order;

    while (!queue.empty()) {
      TreeNode *node = queue.front();
      queue.pop();
      if (!node) {
        order.push_back(std::nullopt);
        continue;
      }

      order.push_back(node->val);

      queue.push(node->left);
      queue.push(node->right);
    }

    while (!order.empty() && !order.back().has_value())
      order.pop_back();

    return join(order, ',');
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(std::string data) {
    auto order = split(data, ',');
    TreeNode *root = nullptr;

    std::queue<TreeNode *> queue;
    int i = 0;
    while (i < order.size()) {
      TreeNode *maybe_left = order[i].has_value() ? new TreeNode(order[i].value()) : nullptr;

      if (i == 0)
        root = maybe_left;

      if (!queue.empty()) {
        TreeNode *parent = queue.front();
        queue.pop();
        if (!parent)
          continue;

        queue.push(maybe_left);
        parent->left = maybe_left;
        TreeNode *right = (i + 1 < order.size() && order[i + 1].has_value())
                              ? new TreeNode(order[i + 1].value())
                              : nullptr;
        queue.push(right);
        parent->right = right;
        i += 2;
      } else {
        queue.push(maybe_left);
        i++;
      }
    }

    return root;
  }

private:
  std::string join(std::vector<std::optional<int>> &strs, char delim) {
    if (strs.empty())
      return "";

    std::stringstream res;
    for (int i = 0; i < strs.size(); i++) {
      res << (strs[i].has_value() ? std::to_string(strs[i].value()) : "n");
      if (i != strs.size() - 1)
        res << delim;
    }
    return res.str();
  }

  std::vector<std::optional<int>> split(std::string &s, char delim) {
    std::vector<std::optional<int>> res;
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
      if (item == "n")
        res.push_back(std::nullopt);
      else
        res.push_back(std::stoi(item));
    }
    return res;
  }
};

// neetcode doesn't include `optional.h`
class CodecNeet {
public:
  // Encodes a tree to a single string.
  std::string serialize(TreeNode *root) {
    std::queue<TreeNode *> queue;
    queue.push(root);

    std::vector<std::string> order;

    while (!queue.empty()) {
      TreeNode *node = queue.front();
      queue.pop();
      if (!node) {
        order.push_back("n");
        continue;
      }

      order.push_back(std::to_string(node->val));

      queue.push(node->left);
      queue.push(node->right);
    }

    while (!order.empty() && order.back() == "n")
      order.pop_back();

    return join(order, ',');
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(std::string data) {
    auto order = split(data, ',');
    TreeNode *root = nullptr;

    std::queue<TreeNode *> queue;
    int i = 0;
    while (i < order.size()) {
      TreeNode *maybe_left = order[i] != "n" ? new TreeNode(std::stoi(order[i])) : nullptr;

      if (i == 0)
        root = maybe_left;

      if (!queue.empty()) {
        TreeNode *parent = queue.front();
        queue.pop();
        if (!parent)
          continue;

        queue.push(maybe_left);
        parent->left = maybe_left;
        TreeNode *right = (i + 1 < order.size() && order[i + 1] != "n")
                              ? new TreeNode(std::stoi(order[i + 1]))
                              : nullptr;
        queue.push(right);
        parent->right = right;
        i += 2;
      } else {
        queue.push(maybe_left);
        i++;
      }
    }

    return root;
  }

private:
  std::string join(std::vector<std::string> &strs, char delim) {
    if (strs.empty())
      return "";

    std::stringstream res;
    for (int i = 0; i < strs.size(); i++) {
      res << strs[i];
      if (i != strs.size() - 1)
        res << delim;
    }
    return res.str();
  }

  std::vector<std::string> split(std::string &s, char delim) {
    std::vector<std::string> res;
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim))
      res.push_back(item);
    return res;
  }
};

int main() {
  Codec codec;
  TreeNode *root =
      new TreeNode(4, new TreeNode(5), new TreeNode(7, new TreeNode(3), new TreeNode(10)));
  std::string serialized = codec.serialize(root);
  std::cout << serialized << std::endl;
  TreeNode *new_root = codec.deserialize(serialized);
  std::cout << codec.serialize(new_root) << std::endl;
}
