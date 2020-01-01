#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 300: Longest Increasing Subsequence. You can find the
 * problem
 * <a href="https://leetcode.com/problems/longest-increasing-subsequence/">
 * here</a>.
 *
 * @param[in] nums: A vector of unsorted integers
 * @returns Given an unsorted array of integers, find the length of longest
 * increasing subsequence.
 */
int length_of_lis(std::vector<int> &nums);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{10,9,2,5,3,7,101,18};
    std::vector<int> test_case_2{2,2};
    std::vector<int> test_case_3{4,10,4,3,8,9};

    assert(length_of_lis(test_case_1) == 4);
    assert(length_of_lis(test_case_2) == 1);
    assert(length_of_lis(test_case_3) == 3);

    return 0;
}

int length_of_lis(std::vector<int> &nums) {
    std::vector<int> output;

    for (std::size_t i = 0; i < nums.size(); i++) {
        bool push_back = true;
        for (std::size_t j = 0; j < output.size(); j++) {
            if (nums[i] < output[j]) {
                output[j] = nums[i];
                push_back = false;
                break;
            } else if (nums[i] == output[j]) {
                push_back = false;
                break;
            }
        }
        if (push_back) output.push_back(nums[i]);
    }

    return output.size();
}
