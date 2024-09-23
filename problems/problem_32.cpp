// https://neetcode.io/problems/find-target-in-rotated-sorted-array

#include <vector>

class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;

        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] < nums[l])
            {
                if (target > nums[m] && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
            else
            {
                if (target < nums[m] && nums[l] <= target)
                    r = m - 1;
                else
                    l = m + 1;
            }
        }

        return -1;
    }
};
