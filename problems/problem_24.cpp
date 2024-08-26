#include <vector>
#include <stack>

class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
    {
        std::vector<int> result(temperatures.size(), 0);
        std::stack<int> q;

        for (int i = temperatures.size() - 1; i >= 0; i--)
        {
            while (!q.empty())
            {
                int j = q.top();
                if (temperatures[i] < temperatures[j])
                {
                    result[i] = j - i;
                    break;
                }
                else
                    q.pop();
            }
            q.push(i);
        }

        return result;
    }
};
