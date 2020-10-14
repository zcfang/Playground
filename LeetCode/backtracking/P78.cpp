#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 78: Subsets. You can find the
 * problem
 * <a href="https://leetcode.com/problems/subsets/">
 * here</a>.
 *
 * @param[in] nums: A vector of distinct integers
 * @returns All possible subsets (the power set)
 */
std::vector<std::vector<int>> subsets(std::vector<int> &nums);

/**
 * Return all possible subsets of `nums`
 *
 * @param[in] index: Index of `nums`
 * @param[in] nums: A vector of distinct integers
 * @param[in] subset: A subset of `nums`
 * @param[in,out] output: All all possible subsets of `nums`
 */
void backtrack(int index, std::vector<int> &nums, std::vector<int> &subset,
               std::vector<std::vector<int>> &output);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1 = {1,2,3};
    std::vector<std::vector<int>> solution = {{}, {1}, {1,2}, {1,2,3}, {1,3},
                                              {2}, {2,3}, {3}};

    assert(subsets(test_case_1) == solution);

    return 0;
}

void backtrack(int index, std::vector<int> &nums, std::vector<int> &subset,
               std::vector<std::vector<int>> &output) {
    output.push_back(subset);
    for (; index < nums.size(); index++) {
        subset.push_back(nums[index]);
        backtrack(index + 1, nums, subset, output);
        subset.pop_back();
    }
}

std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
std::vector<std::vector<int>> output;
    std::vector<int> subset;

    backtrack(0, nums, subset, output);

    return output;
}
