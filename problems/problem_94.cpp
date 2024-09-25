// https://neetcode.io/problems/min-cost-to-connect-points

#include <queue>
#include <unordered_set>
#include <vector>

class Solution
{
public:
    int minCostConnectPoints(std::vector<std::vector<int>> &points)
    {
        const int N = points.size();

        // Prim's
        int total = 0, connected = 0, i = 0;
        std::vector<bool> visited(N);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>>
            min_heap;

        min_heap.push({0, 0});

        while (++connected < N)
        {
            visited[i] = true;
            for (int j = 0; j < N; ++j)
                if (!visited[j])
                    min_heap.push({(std::abs(points[i][0] - points[j][0]) +
                                    std::abs(points[i][1] - points[j][1])),
                                   j});

            while (visited[min_heap.top().second])
                min_heap.pop();

            auto [cost, new_i] = min_heap.top();
            min_heap.pop();
            total += cost;
            i = new_i;
        }

        return total;
    }
};
