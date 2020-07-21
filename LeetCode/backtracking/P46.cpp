#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 46: Permutations. You can find the
 * problem
 * <a href="https://leetcode.com/problems/permutations/">
 * here</a>.
 *
 * @param[in] prices: A vector of numbers
 * @returns Given a collection of distinct integers, return all possible
 * permutations.
 */
std::vector<std::vector<int>> permute(std::vector<int> &nums);

/**
 * Return all permutations of `nums` by backtracking to original state after
 * computing a particular permutation.
 *
 * @param[in] first: Index to fix when computing a particular permutation
 * @param[in] nums: A vector of numbers
 * @param[in,out] output: Permutations of `nums`
 */
void backtrack(int first,
               std::vector<int> &nums,
               std::vector<std::vector<int>> &output);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{1,2,3};
    std::vector<std::vector<int>> solution{{1,2,3}, {1,3,2}, {2,1,3},
                                           {2,3,1}, {3,2,1}, {3,1,2}};

    assert(permute(test_case_1) == solution);

    return 0;
}

void backtrack(int first,
               std::vector<int> &nums,
               std::vector<std::vector<int>> &output) {
    if (first == nums.size()) {
        output.push_back(nums);
    } else {
        for (int i = first; i < nums.size(); i++) {
            std::swap(nums[first], nums[i]);
            backtrack(first + 1, nums, output);
            std::swap(nums[first], nums[i]);
        }
    }
}

std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::vector<std::vector<int>> output;

    backtrack(0, nums, output);

    return output;
}
