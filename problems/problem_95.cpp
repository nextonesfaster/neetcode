#include <queue>
#include <vector>

typedef std::pair<int, int> pii;

class Solution
{
public:
    int networkDelayTime(std::vector<std::vector<int>> &times, int n, int k)
    {
        // padding since our nodes are from [1,n]
        std::vector<std::vector<pii>> graph(n + 1);

        for (const auto &t : times)
            graph[t[0]].emplace_back(t[1], t[2]);

        std::vector<bool> visited(n + 1, false);

        std::vector<int> dist(n + 1, std::numeric_limits<int>::max());
        dist[k] = 0;

        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
        pq.emplace(0, k); // pq is ordered by the cost, so need it first

        while (!pq.empty())
        {
            auto [_, u] = pq.top();
            pq.pop();

            if (visited[u])
                continue;

            visited[u] = true;
            for (auto &[v, w] : graph[u])
            {
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v); // ordered by cost
                }
            }
        }

        int ans = *std::max_element(dist.begin() + 1, dist.end()); // skip padding
        return ans == std::numeric_limits<int>::max() ? -1 : ans;
    }
};
