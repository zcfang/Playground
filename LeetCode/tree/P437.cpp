#include <vector>
#include <unordered_map>
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
 * Problem from LeetCode 437: Path Sum III. You can find
 * the problem
 * <a href="https://leetcode.com/problems/path-sum-iii/">
 * here</a>.
 *
 * @param[in] root: A pointer to the root of a binary tree
 * @param[in] sum: Sum
 * @returns The number of paths that sum to a `sum`
 */
int path_sum(TreeNode *root, int sum);

/**
 * Given a binary tree and a sum, find the number of paths that sum to a given
 * value.
 *
 * @param[in] node: A pointer to a node of a binary tree
 * @param[in] total: Running sum of root-to-leaf path
 * @param[in] sum: Sum
 * @param[in,out] prefix_sum: Running sum of all root-to-leaf path maintained
 * via an unordered map
 * @returns The number of paths that sum to `sum`
 */
int find_path_sum(TreeNode *node, int total, int sum,
                  std::unordered_map<int, int> &prefix_sum);

int main(int argc, char const *argv[]) {

    return 0;
}

int find_path_sum(TreeNode *node, int total, int sum,
                  std::unordered_map<int, int> &prefix_sum) {
    int count = 0;

    if (node) {
        total += node->val;
        count += prefix_sum[total - sum];
        prefix_sum[total]++;
        count += find_path_sum(node->left, total, sum, prefix_sum);
        count += find_path_sum(node->right, total, sum, prefix_sum);
        if (prefix_sum[total] - 1 == 0) {
            prefix_sum.erase(total);
        } else {
            prefix_sum[total]--;
        }
    }

    return count;
}

int path_sum(TreeNode *root, int sum) {
    std::unordered_map<int, int> prefix_sum;

    prefix_sum[0] = 1;

    return find_path_sum(root, 0, sum, prefix_sum);
}
