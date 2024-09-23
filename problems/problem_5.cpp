// https://neetcode.io/problems/top-k-elements-in-list

#include <vector>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> map;
    for (auto num : nums)
      map[num]++;

    // alternate soln
    // vector<pair<int, int>> max_k;
    // max_k.reserve(k + 1);

    // for (auto &nc : map)
    // {
    //     int idx = partitionPoint(max_k, nc.second);
    //     max_k.insert(max_k.begin() + idx, nc);
    //     if (max_k.size() > k)
    //         max_k.pop_back();
    // }

    vector<vector<int>> count_map(nums.size() + 1);
    for (auto &nc : map)
      count_map[nc.second].push_back(nc.first);

    vector<int> res;
    for (int i = count_map.size() - 1; i > 0; --i) {
      for (auto num : count_map[i]) {
        res.push_back(num);
        if (res.size() == k)
          return res;
      }
    }

    return res;
  }

private:
  int partitionPoint(vector<pair<int, int>> &counts, int cnt) {
    if (counts.empty())
      return 0;
    int i = 0;
    while (i < counts.size()) {
      if (counts[i].second <= cnt)
        return i;
      i++;
    }
    return i;
  }
};
