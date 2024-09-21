// https://neetcode.io/problems/count-connected-components

#include <vector>
#include <stack>

class Solution
{
public:
    int countComponents(int n, std::vector<std::vector<int>> &edges)
    {
        std::vector<std::vector<int>> adj_lst(n);
        for (auto &edge : edges)
        {
            adj_lst[edge[0]].push_back(edge[1]);
            adj_lst[edge[1]].push_back(edge[0]);
        }

        int count = 0;
        std::vector<bool> visited(n);

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;

            count++;
            dfs(i, adj_lst, visited);
        }

        return count;
    }

private:
    void dfs(int start, std::vector<std::vector<int>> &adj_lst, std::vector<bool> &visited)
    {
        std::stack<int> stack;
        stack.push(start);

        while (!stack.empty())
        {
            auto node = stack.top();
            stack.pop();
            visited[node] = true;

            for (auto &child : adj_lst[node])
                if (!visited[child])
                    stack.push(child);
        }
    }
};
