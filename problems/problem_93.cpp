// https://neetcode.io/problems/reconstruct-flight-path

#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>> &tickets)
    {
        std::sort(tickets.begin(), tickets.end(),
                  [](const std::vector<std::string> &v1, const std::vector<std::string> &v2)
                  {
                      if (v1[0] == v2[0])
                          return v2[1] < v1[1];
                      return v2[0] < v1[0];
                  });

        std::unordered_map<std::string, std::vector<std::string>> graph;
        for (auto &ticket : tickets)
            graph[ticket[0]].push_back(ticket[1]);

        std::stack<std::string> stack;
        stack.push("JFK");
        std::vector<std::string> itinerary;

        while (!stack.empty())
        {
            auto &src = stack.top();
            if (graph.count(src) && !graph[src].empty())
            {
                stack.push(graph[src].back());
                graph[src].pop_back();
            }
            else
            {
                itinerary.push_back(src);
                stack.pop();
            }
        }

        std::reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};

int main()
{
    std::vector<std::vector<std::string>> tickets = {
        {"BUF", "HOU"}, {"HOU", "SEA"}, {"JFK", "BUF"}};
    Solution sol;
    sol.findItinerary(tickets);
}
