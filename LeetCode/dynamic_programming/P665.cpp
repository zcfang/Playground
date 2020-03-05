#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 665: Non-decreasing Array. You can find the problem
 * <a href="https://leetcode.com/problems/non-decreasing-array/">
 * here</a>.
 *
 * @param[in] nums: An array of numbers
 * @returns Sum of maximum subarray in `nums`
 */
bool check_possibility(std::vector<int> &nums);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1 = {4,2,3};
    std::vector<int> test_case_2 = {4,2,1};

    assert(check_possibility(test_case_1));
    assert(!check_possibility(test_case_2));

    return 0;
}

bool check_possibility(std::vector<int> &nums) {
    int count = 0;

    for (std::size_t i = 0; i < nums.size() - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            if (i == 0) {
                nums[i] = nums[i + 1];
            } else if (nums[i + 1] >= nums[i - 1]) {
                nums[i] = nums[i + 1];
            } else {
                nums[i + 1] = nums[i];
            }
            count++;
        }
        if (count > 1) return false;
    }
    
    return true;
}
