// https://neetcode.io/problems/buy-and-sell-crypto

#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int l = 0, max_profit = 0;

    for (int r = 0; r < prices.size(); r++) {
      if (prices[r] > prices[l])
        max_profit = std::max(max_profit, prices[r] - prices[l]);
      else
        l = r;
    }

    return max_profit;
  }
};
