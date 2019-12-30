#include <assert.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Problem from LeetCode 938: Range Sum of BST. You can find the
 * problem
 * <a href="https://leetcode.com/problems/range-sum-of-bst/">
 * here</a>.
 *
 * @param[in] root: Root of a tree
 * @param[in] L: Lower bound
 * @param[in] R: Upper bound
 * @returns Given the root node of a binary search tree, return the sum of
 * values of all nodes with value between L and R (inclusive).
 */
int range_sum_bst(TreeNode *root, int L, int R);

int main(int argc, char const *argv[]) {

    return 0;
}

int range_sum_bst(TreeNode *root, int L, int R) {
    int value = 0;

    if (root != NULL) {
        value += range_sum_bst(root->left, L, R);
        if (root->val >= L && root->val <= R) value += root->val;
        value += range_sum_bst(root->right, L, R);
    }
    
    return value;
}
