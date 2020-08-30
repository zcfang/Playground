#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 628: Maximum Product of Three Numbers. You can find
 * the problem
 * <a href="https://leetcode.com/problems/maximum-product-of-three-numbers/">
 * here</a>.
 *
 * @param[in] nums: A vector of numbers
 * @returns Maximum product of three numbers
 */
int maximum_product(std::vector<int> &nums);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1 = {1,2,3};
    int solution = 6;

    assert(maximum_product(test_case_1) == solution);

    return 0;
}

int maximum_product(std::vector<int> &nums) {
    int min_1 = INT_MAX;
        int min_2 = INT_MAX;
        int max_1 = INT_MIN;
        int max_2 = INT_MIN;
        int max_3 = INT_MIN;
        int output;

        for (const int n : nums) {
            if (n <= min_1) {
                min_2 = min_1;
                min_1 = n;
            } else if (n <= min_2) {
                min_2 = n;
            }
            if (n >= max_1) {
                max_3 = max_2;
                max_2 = max_1;
                max_1 = n;
            } else if (n >= max_2) {
                max_3 = max_2;
                max_2 = n;
            } else if (n >= max_3) {
                max_3 = n;
            }
        }
        output = std::max(min_1 * min_2 * max_1, max_1 * max_2 * max_3);

        return output;
}
