// https://neetcode.io/problems/median-of-two-sorted-arrays

#include <cstdlib>
#include <vector>

class Solution {
public:
  double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::vector<int> &smaller = nums1, &larger = nums2;
    if (nums1.size() > nums2.size())
      std::swap(smaller, larger);

    const int M = smaller.size(), N = larger.size(), HALF = (M + N + 1) >> 1;
    int l = 0, r = M;
    const bool is_even = (M & 1) == (N & 1);

    while (l <= r) {
      int smaller_m = (l + r) >> 1;
      int larger_m = HALF - smaller_m;

      int smaller_lval = smaller_m > 0 ? smaller[smaller_m - 1] : INT_MIN;
      int larger_lval = larger_m > 0 ? larger[larger_m - 1] : INT_MIN;
      int smaller_rval = smaller_m < M ? smaller[smaller_m] : INT_MAX;
      int larger_rval = larger_m < N ? larger[larger_m] : INT_MAX;

      if (smaller_lval <= larger_rval && larger_lval <= smaller_rval) {
        if (is_even)
          return static_cast<double>(std::max(smaller_lval, larger_lval) +
                                     std::min(smaller_rval, larger_rval)) /
                 2.0;
        else
          return static_cast<double>(std::max(smaller_lval, larger_lval));
      } else if (smaller_lval > larger_rval)
        r = smaller_m - 1;
      else
        l = smaller_m + 1;
    }

    std::abort(); // unreachable
  }
};
