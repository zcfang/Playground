#include <vector>
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
 * Problem from LeetCode 94: Binary Tree Inorder Traversal. You can find the
 * problem
 * <a href="https://leetcode.com/problems/binary-tree-inorder-traversal/">
 * here</a>.
 *
 * @param[in] root: A pointer to the root of a binary tree
 * @returns Nodes of binary tree organized inorder
 */
std::vector<int> inorder_traversal(TreeNode *root);

int main(int argc, char const *argv[]) {

    return 0;
}

std::vector<int> inorder_traversal(TreeNode *root) {
    std::vector<int> output;
    std::stack<TreeNode*> nodes;
    TreeNode *current = root;

    while (!nodes.empty() || current) {
        if (current) {
            nodes.push(current);
            current = current->left; 
        } else {
            output.push_back(nodes.top()->val);
            current = nodes.top()->right;
            nodes.pop();
        }
    }

    return output;
}
