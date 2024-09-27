// https://neetcode.io/problems/climbing-stairs

class Solution
{
public:
    // Fibonacci in disguise
    int climbStairs(int n)
    {
        if (n == 1 || n == 2)
            return n;

        int n_minus_one = 2, n_minus_two = 1, res = 0;

        // f(n) = f(n-1) + f(n-2)
        for (int i = 2; i < n; i++)
        {
            res = n_minus_one + n_minus_two;
            n_minus_two = n_minus_one;
            n_minus_one = res;
        }

        return res;
    }
};
