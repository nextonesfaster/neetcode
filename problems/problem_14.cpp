// https://neetcode.io/problems/trapping-rain-water

#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.empty())
            return 0;

        int l = 0, r = height.size() - 1;
        int max_l = height[l], max_r = height[r];

        int total_area = 0;

        while (l < r)
        {
            if (max_l < max_r)
            {
                l++;
                max_l = max(max_l, height[l]);
                total_area += max_l - height[l];
            }
            else
            {
                r--;
                max_r = max(max_r, height[r]);
                total_area += max_r - height[r];
            }
        }

        return total_area;
    }
};

// ALTERNATIVE; SLOW
// class Solution
// {
// public:
//     int trap(vector<int> &height)
//     {
//         int n = height.size();
//         vector<int> max_after(n, 0);
//         int max_i = n - 1;
//         for (int i = n - 2; i > -1; i--)
//         {
//             max_after[i] = max_i;
//             if (height[i] > height[max_i])
//                 max_i = i;
//         }

//         int i = 0;
//         int total_area = 0;
//         while (i < height.size())
//         {
//             // skip to taller consecutive buildings; only need to check this at the beginning
//             while (i + 1 < height.size() && height[i] <= height[i + 1])
//                 i++;

//             // find segment
//             int curr = i;
//             bool entered = false;
//             while (i < max_after[curr])
//             {
//                 i++;
//                 entered = true;
//                 // next tallest
//                 if (height[i] > height[curr])
//                     break;
//             }

//             if (!entered)
//             {
//                 i++;
//                 continue;
//             }

//             // calculate area of this segment
//             int segment_height = min(height[i], height[curr]);
//             for (int j = curr + 1; j < i; j++)
//                 total_area += segment_height - height[j];
//         }

//         return total_area;
//     }
// };

int main()
{
    Solution solution;
    vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    assert(solution.trap(h) == 6);

    h = {4, 2, 0, 3, 2, 5};
    assert(solution.trap(h) == 9);

    h = {5, 4, 1, 2};
    assert(solution.trap(h) == 1);

    h = {0};
    assert(solution.trap(h) == 0);
}
