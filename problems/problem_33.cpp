// https://neetcode.io/problems/time-based-key-value-store

#include <string>
#include <unordered_map>
#include <vector>

class TimeMap {
private:
  std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> items_map;

  int max_bin_search(std::vector<std::pair<std::string, int>> &items, int target) {
    int l = 0, r = items.size() - 1;

    while (l <= r) {
      int m = l + (r - l) / 2;

      if (items[m].second == target)
        return m;
      else if (items[m].second < target)
        l = m + 1;
      else
        r = m - 1;
    }

    return r;
  }

public:
  TimeMap() {}

  void set(std::string key, std::string value, int timestamp) {
    items_map[key].push_back({value, timestamp});
  }

  std::string get(std::string key, int timestamp) {
    if (items_map.count(key)) {
      int res = max_bin_search(items_map[key], timestamp);
      return (res == -1) ? "" : items_map[key][res].first;
    } else
      return "";
  }
};
