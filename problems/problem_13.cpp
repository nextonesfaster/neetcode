// https://neetcode.io/problems/max-water-container

#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1, max_area = 0;

        while (l < r)
        {
            max_area = max(max_area, min(height[l], height[r]) * (r - l));
            if (height[l] > height[r])
                r--;
            else
                l++;
        }

        return max_area;
    }
};