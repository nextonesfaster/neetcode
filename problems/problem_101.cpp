// https://neetcode.io/problems/house-robber

#include <vector>

class Solution
{
public:
    int rob(std::vector<int> &nums)
    {
        int one = 0, two = 0;

        for (auto n : nums)
        {
            int temp = std::max(n + one, two);
            one = two;
            two = temp;
        }

        return two;
    }
};
