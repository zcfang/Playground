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
 * Problem from LeetCode 113: Path Sum II. You can find
 * the problem
 * <a href="https://leetcode.com/problems/path-sum-ii/">
 * here</a>.
 *
 * @param[in] root: A pointer to the root of a binary tree
 * @param[in] sum: Sum
 * @returns All root-to-leaf paths that sums to `sum`
 */
std::vector<std::vector<int>> path_sum(TreeNode *root, int sum);

/**
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 *
 * @param[in] root: A pointer to the root of a binary tree
 * @param[in] sum: Sum
 * @param[in] total: Running total of root-to-leaf path
 * @param[in] path: Path from root to leaf
 * @param[in,out] output: All root-to-leaf paths that sums to `sum`
 */
void get_path_sum(TreeNode *node, int sum, int total, std::vector<int> path,
                  std::vector<std::vector<int>> &output);

int main(int argc, char const *argv[]) {

    return 0;
}

void get_path_sum(TreeNode *node, int sum, int total, std::vector<int> path,
                  std::vector<std::vector<int>> &output) {
    if (node) {
        if (total + node->val == sum && !node->left && !node->right) {
            path.push_back(node->val);
            output.push_back(path);
            return;
        }
        total += node->val;
        path.push_back(node->val);
        get_path_sum(node->left, sum, total, path, output);
        get_path_sum(node->right, sum, total, path, output);
    }
}

std::vector<std::vector<int>> path_sum(TreeNode *root, int sum) {
    int total = 0;
    std::vector<int> path;
    std::vector<std::vector<int>> output;

    get_path_sum(root, sum, total, path, output);

    return output;
}
