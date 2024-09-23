// https://neetcode.io/problems/kth-smallest-integer-in-bst

#include <stack>

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        std::stack<TreeNode *> stack;
        TreeNode *curr = root;

        while (!stack.empty() || curr)
        {
            while (curr)
            {
                stack.push(curr);
                curr = curr->left;
            }

            curr = stack.top();
            stack.pop();
            k--;
            if (k == 0)
                return curr->val;
            curr = curr->right;
        }

        return -1;
    }
};
