// https://neetcode.io/problems/find-median-in-a-data-stream

#include <queue>
#include <vector>

class MedianFinder
{
    std::priority_queue<int> max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

public:
    MedianFinder() {}

    void addNum(int num)
    {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();
        if (min_heap.size() > max_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian()
    {
        return (max_heap.size() == min_heap.size())
                   ? (static_cast<double>(max_heap.top() + min_heap.top()) / 2.0)
                   : max_heap.top();
    }
};
