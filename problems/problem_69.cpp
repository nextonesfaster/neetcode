// https://neetcode.io/problems/combination-target-sum

#include <vector>

class Solution
{
    int target;
    std::vector<int> nums;
    std::vector<std::vector<int>> res;

    void backtrack(std::vector<int> &curr, int curr_index, int total)
    {
        if (total == target)
        {
            res.push_back(curr); // creates a copy
            return;
        }
        else if (curr_index >= nums.size() || total > target)
            return;

        curr.push_back(nums[curr_index]);
        backtrack(curr, curr_index, total + nums[curr_index]);
        curr.pop_back();
        backtrack(curr, curr_index + 1, total);
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &nums, int target)
    {
        this->nums = nums;
        this->target = target;
        std::vector<int> curr = {};
        backtrack(curr, 0, 0);

        return res;
    }
};
