#include <assert.h>

/**
 * Problem from LeetCode 231: Power of Two. You can find the problem
 * <a href="https://leetcode.com/problems/power-of-two/">
 * here</a>.
 *
 * @param[in] n: A 32 bit number
 * @returns A boolean indicating whether n is a power of two
 */
bool is_power_of_two(int n);

int main(int argc, char const *argv[]) {
    int test_case_1 = 1;
    int test_case_2 = 3;

    assert(is_power_of_two(test_case_1));
    assert(!is_power_of_two(test_case_2));

    return 0;
}

bool is_power_of_two(int n) {
    if (n <= 0) return false;
    return ((n & (n - 1)) == 0);
}
