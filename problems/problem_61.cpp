// https://neetcode.io/problems/kth-largest-integer-in-a-stream

#include <queue>
#include <vector>

class KthLargest
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    int k;

public:
    KthLargest(int k, std::vector<int> &nums) : k(k)
    {
        for (auto n : nums)
            add(n);
    }

    int add(int val)
    {
        if (min_heap.size() < k)
            min_heap.push(val);
        else if (val > min_heap.top())
        {
            min_heap.pop();
            min_heap.push(val);
        }
        return min_heap.top();
    }
};
