// https://neetcode.io/problems/two-integer-sum

#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> posMap;
        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if (posMap.find(diff) != posMap.end())
                return {posMap[diff], i};
            posMap[nums[i]] = i;
        }

        return {};
    }
};

int main() {}
