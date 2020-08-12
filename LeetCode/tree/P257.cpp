#include <vector>
#include <string>
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
 * Problem from LeetCode 257: Binary Tree Paths. You can find the
 * problem
 * <a href="https://leetcode.com/problems/binary-tree-paths/">
 * here</a>.
 *
 * @param[in] root: A pointer to the root of a binary tree
 * @returns All root-to-leaf paths
 */
std::vector<std::string> binary_tree_paths(TreeNode *root);

/**
 * Builds all root-to-leef paths
 *
 * @param[in] root: A pointer a node of a binary tree
 * @param[in] path: A string representing the path from root-to-leef
 * @param[in,out] output: All root-to-leef paths
 */
void build_path(TreeNode *root, std::string path,
                std::vector<std::string> &output);
int main(int argc, char const *argv[]) {

    return 0;
}

void build_path(TreeNode *root, std::string path,
                std::vector<std::string> &output) {
    if (root) {
        path += std::to_string(root->val);
        path += "->";
        build_path(root->left, path, output);
        build_path(root->right, path, output);
        if (!root->left && !root->right) {
            path.pop_back();
            path.pop_back();
            output.push_back(path);
        }
    }        
}

std::vector<std::string> binary_tree_paths(TreeNode *root) {
    std::vector<std::string> output;
    std::string path = "";
    build_path(root, path, output);

    return output;
}
