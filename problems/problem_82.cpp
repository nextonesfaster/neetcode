// https://neetcode.io/problems/clone-graph

#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
 * Definition for a Node.
 */
class Node {
public:
  int val;
  std::vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node *>();
  }
  Node(int _val, std::vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
  std::unordered_map<int, Node *> cloned_nodes;

public:
  Node *cloneGraph(Node *node) {
    if (!node)
      return nullptr;

    std::unordered_set<int> visited;
    std::stack<Node *> stack;
    stack.push(node);

    while (!stack.empty()) {
      Node *curr = stack.top();
      stack.pop();

      if (!cloned_nodes.count(curr->val))
        cloned_nodes[curr->val] = new Node(curr->val);

      if (visited.count(curr->val))
        continue;

      visited.insert(curr->val);

      for (auto &neighbour : curr->neighbors)
        if (neighbour && !visited.count(neighbour->val))
          stack.push(neighbour);
    }

    visited.clear();
    stack.push(node);

    while (!stack.empty()) {
      Node *curr = stack.top();
      stack.pop();

      if (visited.count(curr->val))
        continue;

      visited.insert(curr->val);

      Node *cloned = cloned_nodes[curr->val];
      for (auto &neighbour : curr->neighbors) {
        if (!neighbour)
          continue;

        cloned->neighbors.push_back(cloned_nodes[neighbour->val]);
        if (!visited.count(neighbour->val))
          stack.push(neighbour);
      }
    }

    return cloned_nodes[node->val];
  }
};
