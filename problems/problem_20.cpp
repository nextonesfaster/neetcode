// https://neetcode.io/problems/sliding-window-maximum

#include <vector>
#include <deque>

class Solution
{
public:
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
    {
        int n = nums.size();
        std::vector<int> res;
        res.reserve(n - k + 1);

        std::deque<int> deque;
        int l = 0;

        for (int r = 0; r < n; r++)
        {
            while (!deque.empty() && nums[deque.back()] < nums[r])
                deque.pop_back();

            deque.push_back(r);

            if (l > deque.front())
                deque.pop_front();

            if (r + 1 >= k)
            {
                res.push_back(nums[deque.front()]);
                l++;
            }
        }

        return res;
    }
};
