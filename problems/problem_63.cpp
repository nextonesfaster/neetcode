// https://neetcode.io/problems/k-closest-points-to-origin

#include <vector>
#include <cmath>
#include <queue>

class Solution
{
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points, int k)
    {
        auto distance = [](std::pair<int, int> &point)
        { return std::pow(point.first, 2) + std::pow(point.second, 2); };
        auto cmp = [distance](std::pair<int, int> &p1, std::pair<int, int> &p2)
        { return distance(p1) > distance(p2); }; // min-heap

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> queue(cmp);
        for (auto p : points)
            queue.push({p[0], p[1]});

        std::vector<std::vector<int>> res;
        for (int i = 0; i < k; i++)
        {
            std::pair<int, int> p = queue.top();
            res.push_back({p.first, p.second});
            queue.pop();
        }
        return res;
    }
};
