// https://neetcode.io/problems/minimum-stack

#include <stack>

class MinStack
{
    std::stack<std::pair<int, int>> vals;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (vals.empty())
            vals.push({val, val});
        else
            vals.push({val, std::min(vals.top().second, val)});
    }

    void pop()
    {
        vals.pop();
    }

    int top()
    {
        return vals.top().first;
    }

    int getMin()
    {
        return vals.top().second;
    }
};
