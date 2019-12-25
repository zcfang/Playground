#include <vector>
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
 * Problem from LeetCode 104: Maximum Depth of Binary Tree. You can find the
 * problem
 * <a href="https://leetcode.com/problems/maximum-depth-of-binary-tree/">
 * here</a>.
 *
 * @param[in] root: A pointer to the root of a binary tree
 * @returns Maximum depth of a binary tree
 */
int max_depth(TreeNode* root);

int main(int argc, char const *argv[]) {

    return 0;
}

int max_depth(TreeNode* root) {
    int left_len = 0;
    int right_len = 0;
    int max_len = 0;

    if (root != NULL) {
        left_len = max_depth(root->left);
        right_len = max_depth(root->right);
        max_len = left_len > right_len ? left_len : right_len;
        max_len++;
    }
    
    return max_len;
}
