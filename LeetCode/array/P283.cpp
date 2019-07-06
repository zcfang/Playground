#include <vector>
#include <queue>
#include <assert.h>

/**
 * Problem from LeetCode 283: Move Zeros. You can find the problem
 * <a href="https://leetcode.com/problems/move-zeroes/">
 * here</a>.
 *
 * @param[in] nums: A vector of numbers
 */
void move_zeroes(std::vector<int> &nums); 

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{0,1,0,3,12};

    return 0;
}

void move_zeroes(std::vector<int> &nums) {
    std::queue<int> zero_index;

    for (std::size_t i = 0; i < nums.size(); i++) {
        if (!nums[i]) zero_index.push(i);
        else {
            if (!zero_index.empty()) {
                nums[zero_index.front()] = nums[i];
                nums[i] = 0;
                zero_index.pop();
                zero_index.push(i);
            }
        }
    }
}