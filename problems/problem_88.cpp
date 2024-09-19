// https://neetcode.io/problems/course-schedule-ii

#include <vector>
#include <queue>

class Solution
{
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites)
    {
        std::vector<std::vector<int>> prereqs(numCourses);
        std::vector<int> in_degree(numCourses, 0);

        for (auto &pair : prerequisites)
        {
            prereqs[pair[1]].push_back(pair[0]); // [1] is prereq of [0]
            in_degree[pair[0]]++;
        }

        std::queue<int> no_reqs;
        for (int i = 0; i < numCourses; i++)
            if (in_degree[i] == 0)
                no_reqs.push(i);

        std::vector<int> res;

        while (!no_reqs.empty())
        {
            int n = no_reqs.front();
            no_reqs.pop();
            res.push_back(n);

            for (auto &v : prereqs[n])
            {
                in_degree[v]--;
                if (in_degree[v] == 0)
                    no_reqs.push(v);
            }
        }

        if (res.size() != numCourses)
            return {};
        else
            return res;
    }
};
