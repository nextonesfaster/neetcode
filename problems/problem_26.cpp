// https://neetcode.io/problems/car-fleet

#include <vector>

class Solution
{
public:
    int carFleet(int target, std::vector<int> &position, std::vector<int> &speed)
    {
        std::vector<std::pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++)
            cars.push_back({position[i], speed[i]});

        std::sort(cars.begin(), cars.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b)
                  { return a.first > b.first; });

        float last = std::numeric_limits<float>::min();
        int n = 0;
        for (int i = 0; i < cars.size(); i++)
        {
            float time = static_cast<float>(target - cars[i].first) / static_cast<float>(cars[i].second);
            if (time > last)
            {
                last = time;
                n++;
            }
        }

        return n;
    }
};
