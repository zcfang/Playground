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
 * Problem from LeetCode 129: Sum Root to Leaf Numbers. You can find the
 * problem
 * <a href="https://leetcode.com/problems/sum-root-to-leaf-numbers/">
 * here</a>.
 *
 * @param[in] root: A pointer to the root of a binary tree
 * @returns The total sum of all root-to-leaf numbers.
 */
int sum_numbers(TreeNode* root);

/**
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path
 * represents a number. An example is the root-to-leaf path 1->2->3 which
 * represents the number 123.
 *
 * @param[in] root: A pointer to a node of a binary tree
 * @param[in] num: A number constructed by traversing `root` from root to leaf
 * @returns The total sum of all root-to-leaf numbers.
 */
int get_sum(TreeNode *root, int num);

int main(int argc, char const *argv[]) {

    return 0;
}

int get_sum(TreeNode *root, int num) {
    int total = 0;

    if (root) {
        num = num * 10 + root->val;
        total += get_sum(root->left, num);
        total += get_sum(root->right, num);
        if (!root->left && !root->right) {
            return num;
        }
    }

    return total;
}

int sum_numbers(TreeNode* root) {
    return get_sum(root, 0);
}
