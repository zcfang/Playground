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
 * Problem from LeetCode 101: Symmetric Tree. You can find the
 * problem
 * <a href="https://leetcode.com/problems/symmetric-tree/">
 * here</a>.
 *
 * @param[in] root: A pointer to the root of a binary tree
 * @returns True if `root` is symmetric around its center
 */
bool is_symmetric(TreeNode* root);

int main(int argc, char const *argv[]) {

    return 0;
}

bool is_symmetric(TreeNode* root) {
    TreeNode *left = root;
    TreeNode *right = root;
    std::stack<TreeNode*> left_tree;
    std::stack<TreeNode*> right_tree;

    while ((!left_tree.empty() || left) && (!right_tree.empty() || right)) {
        if (left) {
            left_tree.push(left);
            left = left->left;
        } else {
            left = left_tree.top()->right;
            left_tree.pop();
        }
        if (right) {
            right_tree.push(right);
            right = right->right;
        } else {
            right = right_tree.top()->left;
            right_tree.pop();
        }
        if ((left && right && left->val != right->val) ||
            (left && !right) || (!left && right)) return false;
    }

    return true;
}
