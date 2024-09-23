// https://neetcode.io/problems/binary-tree-maximum-path-sum

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
    int maxPathSum(TreeNode *root)
    {
        int res = root->val;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode *root, int &res)
    {
        if (!root)
            return 0;

        int left = std::max(dfs(root->left, res), 0);
        int right = std::max(dfs(root->right, res), 0);

        res = std::max(res, root->val + left + right);
        return root->val + std::max(left, right);
    }
};
