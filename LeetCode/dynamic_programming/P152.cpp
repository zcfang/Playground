#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 152: Maximum Product Subarray. You can find the
 * problem
 * <a href="https://leetcode.com/problems/maximum-product-subarray/">
 * here</a>.
 *
 * @param[in] nums: A vector of numbers
 * @returns Given an integer array nums, find the contiguous subarray within an
 * array (containing at least one number) which has the largest product.
 */
int max_product(std::vector<int> &nums);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{-2,-2,-2,-2};
    std::vector<int> test_case_2{-2,3,4};
    std::vector<int> test_case_3{0,2};
    std::vector<int> test_case_4{};
    std::vector<int> test_case_5{-2,0,-1};
    std::vector<int> test_case_6{2,3,-2,4};
    std::vector<int> test_case_7{-2,0,-1,-3};

    assert(max_product(test_case_1) == 16);
    assert(max_product(test_case_2) == 12);
    assert(max_product(test_case_3) == 2);
    assert(max_product(test_case_4) == 0);
    assert(max_product(test_case_5) == 0);
    assert(max_product(test_case_6) == 6);
    assert(max_product(test_case_7) == 3);

    return 0;
}

int max_product(std::vector<int> &nums) {
    int max_value = nums.size() < 1 ? 0 : nums[0];
    int min_value = nums.size() < 1 ? 0 : nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int temp = nums[i];
        nums[i] = std::max(min_value * nums[i], nums[i - 1] * nums[i]);
        nums[i] = std::max(temp, nums[i]);
        min_value = std::min(min_value * temp, nums[i - 1] * temp);
        min_value = std::min(min_value, temp);
        max_value = std::max(max_value, nums[i]);
    }

    return max_value;
}
