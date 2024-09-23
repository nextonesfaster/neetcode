// https://neetcode.io/problems/validate-parentheses

#include <stack>
#include <string>

class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> stack;
    for (auto c : s) {
      if (c == '[' || c == '{' || c == '(')
        stack.push(c);
      else {
        char popped = stack.top();
        stack.pop();
        if ((c == ']' && popped != '[') || (c == '}' && popped != '{') ||
            (c == ')' && popped != '('))
          return false;
      }
    }
    return stack.empty();
  }
};
