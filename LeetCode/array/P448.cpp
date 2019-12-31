#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 448: Find All Numbers Disappeared in an Array.
 * You can find the problem
 * <a href="https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/">
 * here</a>.
 *
 * @param[in] nums: A vector of numbers
 * @returns A vector with elements of [1, n] (n = size of array) inclusive that
 * does not appear in nums 
 */
std::vector<int> find_disappeared_numbers(std::vector<int> &nums);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{4,3,2,7,8,2,3,1};
    std::vector<int> solution{5,6};

    assert(find_disappeared_numbers(test_case_1) == solution);

    return 0;
}

std::vector<int> find_disappeared_numbers(std::vector<int> &nums) {
    int i = 0;
    std::vector<int> output;
    
    while (i < nums.size()) {
        if (nums[nums[i] - 1] != nums[i]) {
            std::swap(nums[i], nums[nums[i] - 1]);
        } else i++;
    }
    
    for (std::size_t i = 0; i < nums.size(); i++) {
        if (nums[i] != i + 1) output.push_back(i + 1);
    }

    return output;
}