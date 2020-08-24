#include <queue>
#include <vector>
#include <assert.h>

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),
                                                        left(left),
                                                        right(right) {}
 };
 

/**
 * Problem from LeetCode 102: Binary Tree Level Order Traversal. You can find
 * the problem
 * <a href="https://leetcode.com/problems/binary-tree-level-order-traversal/">
 * here</a>.
 *
 * @param[in] root: A pointer to the root of a binary tree
 * @returns The level order traversal of its nodes' values. (ie, from left to
 * right, level by level).
 */
std::vector<std::vector<int>> level_order(TreeNode *root);

int main(int argc, char const *argv[]) {

    return 0;
}

std::vector<std::vector<int>> level_order(TreeNode *root) {
    std::vector<std::vector<int>> output;
    std::queue<TreeNode*> nodes;

    if (root) {
        nodes.push(root);
        nodes.push(nullptr);
    }
    while (!nodes.empty()) {
        std::vector<int> level;
        while (nodes.front()) {
            TreeNode *front = nodes.front();
            nodes.pop();
            level.push_back(front->val);
            if (front->left) {
                nodes.push(front->left);
            }
            if (front->right) {
                nodes.push(front->right);
            }
        }
        nodes.pop();
        if (!nodes.empty()) {
            nodes.push(nullptr);
        }
        output.push_back(level);
    }

    return output;
}
