#include <string>
#include <vector>
#include <stack>

class Solution
{
public:
    int evalRPN(std::vector<std::string> &tokens)
    {
        std::stack<int> stack;
        for (auto &token : tokens)
        {
            if (token == "+")
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b + a);
            }
            else if (token == "-")
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b - a);
            }
            else if (token == "*")
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b * a);
            }
            else if (token == "/")
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b / a);
            }
            else
                stack.push(std::stoi(token));
        }
        return stack.top();
    }
};
