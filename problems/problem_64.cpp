// https://neetcode.io/problems/kth-largest-element-in-an-array

#include <queue>
#include <vector>

class Solution {
private:
  int partition(std::vector<int> &arr, int l, int r) {
    int pivot = arr[r];
    int stored = l;
    for (int i = l; i < r; i++) {
      if (arr[i] < pivot) {
        std::swap(arr[i], arr[stored]);
        stored++;
      }
    }
    std::swap(arr[stored], arr[r]);
    return stored;
  }

public:
  int findKthLargest(std::vector<int> &nums, int k) {
    k = nums.size() - k;
    int l = 0, r = nums.size() - 1;

    while (l < r) {
      int pivot = partition(nums, l, r);
      if (pivot == k)
        return nums[pivot];
      else if (pivot < k)
        l = pivot + 1;
      else
        r = pivot - 1;
    }

    // unreachable, unless k > nums.size()
    return -1;
  }

  int findKthLargestHeap(std::vector<int> &nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap(nums.begin(), nums.end());
    while (heap.size() > k)
      heap.pop();
    return heap.top();
  }
};
