// https://neetcode.io/problems/largest-rectangle-in-histogram

#include <vector>
#include <stack>

class Solution
{
public:
    int largestRectangleArea(std::vector<int> &heights)
    {
        int n = heights.size();
        std::stack<std::pair<int, int>> stack;
        int max_area = 0, l = 0;

        for (int r = 0; r < n; r++)
        {
            l = r;
            while (!stack.empty() && stack.top().second > heights[r])
            {
                l = stack.top().first;
                max_area = std::max(max_area, stack.top().second * (r - l));
                stack.pop();
            }
            stack.push({r, heights[r]});
        }

        while (!stack.empty())
        {
            max_area = std::max(max_area, stack.top().second * (n - 1 - stack.top().first));
            stack.pop();
        }

        return max_area;
    }
};
