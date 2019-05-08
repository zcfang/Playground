#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 189: Rotate Array. You can find the problem
 * <a href="https://leetcode.com/problems/rotate-array/">
 * here</a>.
 *
 * @param[in] nums: A vector of number
 * @param[in] k: Number of end values to rotate
 */
void rotate(std::vector<int> &nums, int k);

int main(int argc, char const *argv[]) {
    int k_1 = 3;
    int k_2 = 2; 
    std::vector<int> test_case_1{1,2,3,4,5,6,7};
    std::vector<int> test_case_2{-1,-100,3,99};

    rotate(test_case_1, k_1);
    rotate(test_case_2, k_2);

    return 0;
}

void rotate(std::vector<int> &nums, int k) {
    if (!k || k == nums.size()) return;
    k = k % nums.size();
    std::vector<int> rotated_nums;
    rotated_nums.resize(nums.size());
    for (std::size_t i = 0; i < nums.size(); i++) {
        if (i < k) {
            rotated_nums[i] = nums[nums.size() - k + i];
        } else {
            rotated_nums[i] = nums[i - k];
        }
    }
    nums = rotated_nums;
}