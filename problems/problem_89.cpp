// https://neetcode.io/problems/valid-tree

#include <stack>
#include <vector>

class Solution
{
    bool has_cycle(std::vector<std::vector<int>> &adj_lst, std::vector<bool> &visited)
    {
        std::stack<std::pair<int, int>> stack;
        stack.push({-1, 0});

        while (!stack.empty())
        {
            auto [parent, node] = stack.top();
            if (visited[node])
                return true;

            stack.pop();

            visited[node] = true;
            for (auto &child : adj_lst[node])
            {
                if (child != parent)
                    stack.push({node, child});
            }
        }

        return false;
    }

public:
    bool validTree(int n, std::vector<std::vector<int>> &edges)
    {
        std::vector<std::vector<int>> adj_lst(n);

        for (auto &pair : edges)
        {
            adj_lst[pair[0]].push_back(pair[1]);
            adj_lst[pair[1]].push_back(pair[0]);
        }

        std::vector<bool> visited(n);
        if (has_cycle(adj_lst, visited))
            return false;

        for (int i = 0; i < n; i++)
            if (!visited[i])
                return false;

        return true;
    }
};
