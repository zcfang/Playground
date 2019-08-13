#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 53: Maximum Subarray. You can find the problem
 * <a href="https://leetcode.com/problems/maximum-subarray/">
 * here</a>.
 *
 * @param[in] nums: An array of numbers
 * @returns Sum of maximum subarray in `nums`
 */
int max_subarray(std::vector<int> &nums) ;

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1 = {-2,1,-3,4,-1,2,1,-5,4};
    std::vector<int> test_case_2 = {1,2};

    assert(max_subarray(test_case_1) == 6);
    assert(max_subarray(test_case_2) == 3);

    return 0;
}

int max_subarray(std::vector<int> &nums) {
    if (nums.size() == 1) return nums[0];
    int max_value = nums[0];
    std::vector<int> total(nums.size());
    total[0] = nums[0];
    for (std::size_t i = 1; i < nums.size(); i++) {
        total[i] = nums[i] < nums[i] + total[i - 1] ? (nums[i] + total[i - 1]) :
                                                      nums[i];
        max_value = total[i] > max_value ? total[i] : max_value;
    }

    return max_value;
}