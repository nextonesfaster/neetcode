// https://neetcode.io/problems/eating-bananas

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int minEatingSpeed(std::vector<int> &piles, int h) {
    int min_speed = 1, max_speed = *std::max_element(piles.begin(), piles.end());

    while (min_speed < max_speed) {
      int speed = min_speed + (max_speed - min_speed) / 2;
      if (count_hours(piles, speed, h) == -1) // this means hours > h
        min_speed = speed + 1;
      else
        max_speed = speed;
    }

    return max_speed;
  }

  int count_hours(std::vector<int> &piles, int speed, int h) {
    int count = 0;
    for (auto &pile : piles) {
      count += pile / speed + (pile % speed != 0);
      if (count > h)
        return -1;
    }
    return count;
  }
};

int main() {
  Solution solution;
  std::vector<int> piles = {1, 4, 3, 2};
  std::cout << solution.minEatingSpeed(piles, 9) << std::endl;

  piles = {3, 6, 7, 11};
  std::cout << solution.minEatingSpeed(piles, 8) << std::endl;
}
