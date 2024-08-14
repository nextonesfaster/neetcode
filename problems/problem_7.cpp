#include <vector>
#include <assert.h>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> res(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
            res[i] = res[i - 1] * nums[i - 1];

        int suff = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            res[i] = res[i] * suff;
            suff *= nums[i];
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 4, 6};
    assert(solution.productExceptSelf(nums) == vector<int>({48, 24, 12, 8}));
}
