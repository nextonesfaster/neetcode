// https://neetcode.io/problems/cheapest-flight-path

#include <array>
#include <queue>
#include <vector>

typedef std::array<int, 3> arr3;

class Solution
{
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>> &flights, int src, int dst, int k)
    {
        const int MAX = std::numeric_limits<int>::max();
        std::vector<int> prices(n, MAX);
        prices[src] = 0;

        for (int i = 0; i <= k; i++)
        {
            std::vector<int> tmp_prices = prices; // copy; i weep
            for (auto &flight : flights)
            {
                int s = flight[0], d = flight[1], c = flight[2];

                if (prices[s] == MAX)
                    continue;

                if (prices[s] + c < tmp_prices[d])
                    tmp_prices[d] = prices[s] + c;
            }
            prices = tmp_prices;
        }

        return prices[dst] == MAX ? -1 : prices[dst];
    }
};
