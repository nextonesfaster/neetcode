// https://neetcode.io/problems/house-robber-ii

#include <vector>

class Solution
{
public:
    int rob(std::vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        return std::max(rob_helper(nums, 0, nums.size() - 1), rob_helper(nums, 1, nums.size()));
    }

private:
    int rob_helper(std::vector<int> &nums, int start, int end)
    {
        int one = 0, two = 0;
        for (int i = start; i < end; i++)
        {
            int tmp = std::max(one + nums[i], two);
            one = two;
            two = tmp;
        }
        return two;
    }
};
