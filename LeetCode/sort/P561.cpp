#include <vector>
#include <algorithm>
#include <assert.h>

/**
 * Problem from LeetCode 561: Array Partition I. You can find the
 * problem <a href="https://leetcode.com/problems/array-partition-i/">
 * here</a>.
 *
 * @param[in] nums: A vector of numbers
 * @returns Given an array of 2n integers, your task is to group these integers
 * into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes
 * sum of min(ai, bi) for all i from 1 to n as large as possible
 */
int array_pair_sum(std::vector<int> &nums);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{1,4,3,2};

    assert(array_pair_sum(test_case_1) == 4);

    return 0;
}

int array_pair_sum(std::vector<int> &nums) {
    int output = 0;

    std::sort(nums.begin(), nums.end());

    for (std::size_t i = 0; i < nums.size(); i += 2) {
        output += nums[i];
    }

    return output;
}
