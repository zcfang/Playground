#include <cmath>
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
 * Problem from LeetCode 98: Validate Binary Search Tree. You can find the
 * problem
 * <a href="https://leetcode.com/problems/validate-binary-search-tree/">
 * here</a>.
 *
 * @param[in] root: A pointer to the root of a binary tree
 * @returns True if `root` is a valid binary search tree
 */
bool is_valid_bst(TreeNode *root);

/**
 * Determines if `root` is a valid binary serach tree
 *
 * @param[in] root: A pointer to the node of a binary tree
 * @param[in] lower: Lower bound of binary serach tree
 * @param[in] upper: Upper bound of binary serach tree
 * @returns True if `root` is a valid binary search tree
 */
bool valid_subtree(TreeNode *node, double lower, double upper);

int main(int argc, char const *argv[]) {

    return 0;
}

bool valid_subtree(TreeNode *node, double lower, double upper) {
    if (node == NULL) return true;
    int val = node->val;
    if (lower != INFINITY && val <= lower) return false;
    if (upper != INFINITY && val >= upper) return false;
    if (!valid_subtree(node->right, val, upper)) return false;
    if (!valid_subtree(node->left, lower, val)) return false;
    return true;
}

bool is_valid_bst(TreeNode *root) {
    return valid_subtree(root, INFINITY, INFINITY);
}
