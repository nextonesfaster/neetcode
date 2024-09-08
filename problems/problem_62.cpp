// https://neetcode.io/problems/last-stone-weight

#include <vector>
#include <queue>

class Solution
{
public:
    int lastStoneWeight(std::vector<int> &stones)
    {
        std::priority_queue<int, std::vector<int>, std::less<int>> queue(stones.begin(), stones.end());

        while (queue.size() > 1)
        {
            int a = queue.top();
            queue.pop();
            int b = queue.top();
            queue.pop();
            queue.push(std::abs(a - b));
        }

        return queue.top();
    }
};
