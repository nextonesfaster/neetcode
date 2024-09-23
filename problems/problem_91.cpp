// https://neetcode.io/problems/redundant-connection

#include <vector>

class Solution
{
    std::vector<int> parents;
    std::vector<int> rank;

    int find(int n)
    {
        int p = parents[n];
        while (p != parents[p])
        {
            parents[p] = parents[parents[p]];
            p = parents[p];
        }
        return p;
    }

    bool set_union(int n1, int n2)
    {
        int p1 = find(n1), p2 = find(n2);

        if (p1 == p2)
            return false;
        else if (rank[p1] >= rank[p2])
        {
            parents[p2] = p1;
            rank[p1] += rank[p2];
        }
        else
        {
            parents[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }

public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>> &edges)
    {
        int n = edges.size();
        rank = std::vector<int>(n, 1);
        for (int i = 0; i < n; i++)
            parents.push_back(i);

        for (const auto &edge : edges)
            if (!set_union(edge[0] - 1, edge[1] - 1))
                return edge;
        return {};
    }
};
