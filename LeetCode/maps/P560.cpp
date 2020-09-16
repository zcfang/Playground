#include <vector>
#include <unordered_map>
#include <assert.h>

/**
 * Problem from LeetCode 560: Subarray Sum Equals K. You can find the problem
 * <a href="https://leetcode.com/problems/subarray-sum-equals-k/">
 * here</a>.
 *
 * @param[in] nums: A vector of integers
 * @param[in] k: A integer with range [-1e7, 1e7]
 * @returns The total number of continuous subarrays whose sum equals to k
 */
int subarray_sum(std::vector<int> &nums, int k);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1 = {10,5,3,3,-3,-10};
    int k = 8;
    int solution = 3;

    assert(subarray_sum(test_case_1, k) == solution);

    return 0;
}

int subarray_sum(std::vector<int> &nums, int k) {
    int output = 0;
    int total = 0;
    std::unordered_map<int, int> sum_freq;

    sum_freq[0] = 1;
    for (std::size_t i = 0; i < nums.size(); i++) {
        total += nums[i];
        output += sum_freq[total - k];
        sum_freq[total]++;
    }

    return output;
}
