// https://neetcode.io/problems/duplicate-integer

#include <assert.h>
#include <unordered_set>
#include <vector>

class Solution
{
public:
    bool hasDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> set = std::unordered_set<int>();
        for (auto num : nums)
        {
            if (set.find(num) != set.end())
                return true;
            set.insert(num);
        }
        return false;
    }
};

int main()
{
    Solution solution = Solution();

    std::vector<int> v1 = {1, 2, 3, 3};
    bool t1 = solution.hasDuplicate(v1);
    assert(t1 == true);

    std::vector<int> v2 = {1, 2, 3, 4};
    bool t2 = solution.hasDuplicate(v2);
    assert(t2 == false);
}
