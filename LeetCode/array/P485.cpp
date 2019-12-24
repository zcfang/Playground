#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 485: Max Consecutive Ones. You can find the problem
 * <a href="https://leetcode.com/problems/max-consecutive-ones/">
 * here</a>.
 *
 * @param[in] nums: A vector of binary numbers
 * @returns The maximum number of consecutive 1s in nums
 */
int find_max_consecutive_ones(std::vector<int> &nums);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{1,1,0,1,1,1};

    assert(find_max_consecutive_ones(test_case_1) == 3);

    return 0;
}

int find_max_consecutive_ones(std::vector<int> &nums) {
    int output = 0;
    int count = 0;
    for (const int value : nums) {
        if (value) count++;
        else {
            output = count > output ? count : output;
            count = 0;
        }
    }
    output = count > output ? count : output;

    return output;
}