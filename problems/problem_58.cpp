// https://neetcode.io/problems/binary-tree-from-preorder-and-inorder-traversal

#include <unordered_map>
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
    std::unordered_map<int, int> inorder_map;

public:
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
            inorder_map[inorder[i]] = i;

        return build(preorder, 0, inorder, 0, inorder.size() - 1);
    }

    TreeNode *build(std::vector<int> &preorder, int pre, std::vector<int> &inorder, int in_left,
                    int in_right)
    {
        if (pre >= preorder.size() || in_left > in_right)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[pre]);
        int mid = inorder_map[preorder[pre]];

        root->left = build(preorder, pre + 1, inorder, in_left, mid - 1);
        root->right = build(preorder, pre + mid - in_left + 1, inorder, mid + 1, in_right);

        return root;
    }
};
