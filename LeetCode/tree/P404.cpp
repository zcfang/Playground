#include <stack>
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
 * Problem from LeetCode 404: Sum of Left Leaves. You can find the
 * problem
 * <a href="https://leetcode.com/problems/sum-of-left-leaves/">
 * here</a>.
 *
 * @param[in] root: A pointer to the root of a binary tree
 * @returns Sum of all left leaves
 */
int sum_of_left_leaves(TreeNode* root);

int main(int argc, char const *argv[]) {

    return 0;
}

int sum_of_left_leaves(TreeNode* root) {
    int total = 0;
    std::stack<std::pair<TreeNode*, bool>> nodes;

    if (root) {
        nodes.push({root, false});
    }
    while (!nodes.empty()) {
        std::pair<TreeNode*, bool> node = nodes.top();
        nodes.pop();
        if (node.first->right) {
            nodes.push({node.first->right, false});
        }
        if (node.first->left) {
            bool is_leaf = !node.first->left->left && !node.first->left->right;
            nodes.push({node.first->left, is_leaf});
        }
        if (node.second) {
            total += node.first->val;
        }
    }

    return total;
}
