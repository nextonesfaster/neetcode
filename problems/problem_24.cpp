// https://neetcode.io/problems/generate-parentheses

#include <string>
#include <vector>

class Solution {
  class QueueElement {
  public:
    int open;
    int closed;
    std::string s;
    QueueElement(int o, int c, std::string s) : open(o), closed(c), s(s) {}
  };

public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result;
    std::vector<QueueElement> queue = {{0, 0, ""}};

    while (!queue.empty()) {
      QueueElement e = queue.back();
      queue.pop_back();

      if (e.open < n)
        queue.push_back({e.open + 1, e.closed, e.s + '('});

      if (e.closed < e.open)
        queue.push_back({e.open, e.closed + 1, e.s + ')'});

      if (e.s.length() == n * 2)
        result.push_back(e.s);
    }

    return result;
  }
};
