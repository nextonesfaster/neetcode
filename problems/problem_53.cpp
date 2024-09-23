// https://neetcode.io/problems/level-order-traversal-of-binary-tree

#include <queue>
#include <vector>

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
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};

        std::vector<std::vector<int>> res;
        std::queue<TreeNode *> queue;
        queue.push(root);

        while (!queue.empty())
        {
            std::vector<int> level;
            int n = queue.size();
            level.reserve(n);

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = queue.front();
                queue.pop();
                level.push_back(node->val);
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }

            res.push_back(level);
        }

        return res;
    }
};
