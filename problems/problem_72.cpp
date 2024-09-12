// https://neetcode.io/problems/combination-target-sum-ii

#include <algorithm>
#include <vector>

class Solution
{
    std::vector<std::vector<int>> res;
    int target;

    void backtrack(const std::vector<int> &candidates, std::vector<int> &curr, int curr_idx, int curr_total)
    {
        if (curr_total == target)
        {
            res.push_back(curr); // creates a copy
            return;
        }
        else if (curr_total > target || curr_idx > candidates.size())
            return;

        for (int i = curr_idx; i < candidates.size(); i++)
        {
            if (i > curr_idx && candidates[i] == candidates[i - 1])
                continue;

            curr.push_back(candidates[i]);
            backtrack(candidates, curr, i + 1, curr_total + candidates[i]);
            curr.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target)
    {
        this->target = target;
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> curr;
        backtrack(candidates, curr, 0, 0);
        return res;
    }
};
