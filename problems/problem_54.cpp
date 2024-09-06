// https://neetcode.io/problems/binary-tree-right-side-view

#include <vector>
#include <queue>

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
    std::vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return {};

        std::vector<int> res;
        std::queue<TreeNode *> queue;
        queue.push(root);

        while (!queue.empty())
        {
            res.push_back(queue.back()->val);
            int n = queue.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = queue.front();
                queue.pop();
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
        }

        return res;
    }
};
