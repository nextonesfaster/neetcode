// https://neetcode.io/problems/depth-of-binary-tree

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
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        std::stack<std::pair<TreeNode *, int>> stack;
        stack.push({root, 0});

        int max_depth = 0;

        while (!stack.empty())
        {
            auto [node, depth] = stack.top();
            stack.pop();

            max_depth = std::max(depth, max_depth);

            if (node->left)
                stack.push({node->left, depth + 1});

            if (node->right)
                stack.push({node->right, depth + 1});
        }

        return max_depth + 1;
    }
};
