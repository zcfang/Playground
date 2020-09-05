#include <vector>
#include <unordered_set>
#include <assert.h>

/**
 * Problem from LeetCode 47: Permutations II. You can find the
 * problem
 * <a href="https://leetcode.com/problems/permutations-ii/">
 * here</a>.
 *
 * @param[in] prices: A vector of numbers
 * @returns Given a collection of integers, return all unique
 * permutations.
 */
std::vector<std::vector<int>> permute_unique(std::vector<int> &nums);

/**
 * Return all unique permutations of `nums` by backtracking to original state
 * after computing a particular permutation.
 *
 * @param[in] first: Index to fix when computing a particular permutation
 * @param[in] nums: A vector of numbers
 * @param[in,out] output: Permutations of `nums`
 */
void permute(int first,
               std::vector<int> &nums,
               std::vector<std::vector<int>> &output);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{1,1,2};
    std::vector<std::vector<int>> solution{{1,1,2}, {1,2,1}, {2,1,1}};

    assert(permute_unique(test_case_1) == solution);

    return 0;
}

void permute(int first,
               std::vector<int> &nums,
               std::vector<std::vector<int>> &output) {
    if (first == nums.size()) {
        output.push_back(nums);
        return;
    }
    std::unordered_set<int> swapped;
    for (int i = first; i < nums.size(); i++) {
        if (swapped.insert(nums[i]).second) {
            std::swap(nums[first], nums[i]);
            permute(first + 1, nums, output);
            std::swap(nums[first], nums[i]);
        }
    }
}

std::vector<std::vector<int>> permute_unique(std::vector<int> &nums) {
    std::vector<std::vector<int>> output;

    permute(0, nums, output);

    return output;
}
