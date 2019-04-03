#include <vector>

/**
 * Problem from LeetCode 268: Missing Number. You can find the
 * problem
 * <a href="https://leetcode.com/problems/missing-number/">
 * here</a>.
 *
 * @param[in] nums: A vector of number
 * @returns Value missing in continuous vector
 */
int missing_number(std::vector<int> &nums);

int main(int argc, char const *argv[]) {

    return 0;
}

int missing_number(std::vector<int> &nums) {
    int sum = 0;
    int n = nums.size();
    int total = (n + 1) * (n) / 2;

    for (int element : nums) {
        sum += element;
    }

    return total - sum;
}