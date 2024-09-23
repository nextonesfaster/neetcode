// https://neetcode.io/problems/task-scheduling

#include <algorithm>
#include <vector>

class Solution {
public:
  int leastInterval(std::vector<char> &tasks, int n) {
    int size = tasks.size();
    int freq[26] = {0};
    int max_freq = 0;
    for (auto task : tasks)
      max_freq = std::max(max_freq, ++freq[task - 'A']);

    int max_n = std::count(freq, freq + 26, max_freq);

    return std::max(size, (n + 1) * (max_freq - 1) + max_n);
  }
};

int main() {
  Solution sol;
  std::vector<char> tasks = {'X', 'X', 'Y', 'Y'};
  sol.leastInterval(tasks, 2);
}
