// https://neetcode.io/problems/find-minimum-in-rotated-sorted-array

#include <vector>

class Solution {
public:
  int findMin(std::vector<int> &nums) {
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
      int m = l + (r - l) / 2;

      if (nums[r] < nums[m])
        l = m + 1;
      else
        r = m;
    }

    return nums[l];
  }
};
