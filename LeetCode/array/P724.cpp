#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 724: Find Pivot Index. You can find the problem
 * <a href="https://leetcode.com/problems/find-pivot-index/">
 * here</a>.
 *
 * @param[in] nums: A vector of numbers
 * @returns The "pivot" index of `num`. If no such index exists, return -1
 */
int pivot_index(std::vector<int> &nums);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{1,7,3,6,5,6};
    std::vector<int> test_case_2{1,2,3};
    int solution_1 = 3;
    int solution_2 = -1;

    assert(pivot_index(test_case_1) == solution_1);
    assert(pivot_index(test_case_2) == solution_2);

    return 0;
}

int pivot_index(std::vector<int> &nums) {
    int total = 0;
    int running = 0;
    int output = -1;

    for (const int val : nums)
        total += val;
    for (std::size_t i = 0; i < nums.size(); i++) {
        if (total - running - nums[i] == running)
            return i;
        running += nums[i];
    }

    return output;
}