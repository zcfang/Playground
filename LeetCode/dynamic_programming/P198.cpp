#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 198: House Robber. You can find the problem
 * <a href="https://leetcode.com/problems/house-robber/">
 * here</a>.
 *
 * @param[in] nums: A vector of numbers representing amount of gold in each
 * house
 * @returns An integer indicating maximum amount of gold a robber can steal
 */
int rob(std::vector<int> &nums);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{1,2,3,1};
    std::vector<int> test_case_2{2,7,9,3,1};
    std::vector<int> test_case_3{2,1,1,2};

    assert(rob(test_case_1) == 4);
    assert(rob(test_case_2) == 12);
    assert(rob(test_case_3) == 4);

    return 0;
}

int rob(std::vector<int> &nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return std::max(nums[0], nums[1]);
    
    nums[1] = std::max(nums[0], nums[1]);
    for (std::size_t i = 2; i < nums.size(); i++) {
        nums[i] = std::max(nums[i - 1], nums[i] + nums[i - 2]);
    }
    
    return nums.back();
}