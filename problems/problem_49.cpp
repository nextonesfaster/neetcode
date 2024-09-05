// https://neetcode.io/problems/balanced-binary-tree

#include <cstdlib>
#include <algorithm>

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
    bool isBalanced(TreeNode *root)
    {
        bool res = true;
        checkHeight(root, res);
        return res;
    }

    int checkHeight(TreeNode *node, bool &res)
    {
        if (!node || !res)
            return 0;

        int left = checkHeight(node->left, res), right = checkHeight(node->right, res);
        res = res && std::abs(left - right) < 2;
        return std::max(left, right) + 1;
    }
};
