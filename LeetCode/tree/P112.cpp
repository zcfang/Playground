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
 * Problem from LeetCode 112: Path Sum. You can find
 * the problem
 * <a href="https://leetcode.com/problems/path-sum/">
 * here</a>.
 *
 * @param[in] root: A pointer to the root of a binary tree
 * @param[in] sum: Sum
 * @returns True if a root-to-leef path sums to `sum`
 */
bool has_path_sum(TreeNode *root, int sum);

/**
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 *
 * @param[in] root: A pointer to the root of a binary tree
 * @param[in] total: Running total of root-to-leaf path
 * @param[in] sum: Sum
 * @returns True if a root-to-leef path sums to `sum`
 */
bool find_path_sum(TreeNode *root, int total, int sum);

int main(int argc, char const *argv[]) {

    return 0;
}

bool find_path_sum(TreeNode *root, int total, int sum) {
    bool found_path = false;

    if (root) {
        if (total + root->val == sum && !root->left && !root->right)
            return true;
        total += root->val;
        if (find_path_sum(root->left, total, sum)) return true;
        if (find_path_sum(root->right, total, sum)) return true;
    }

    return found_path;
}

bool has_path_sum(TreeNode* root, int sum) {
    return find_path_sum(root, 0, sum);
}
