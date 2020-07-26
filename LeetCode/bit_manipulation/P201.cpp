#include <assert.h>

/**
 * Problem from LeetCode 201: Bitwise AND of Numbers Range. You can find the
 * problem
 * <a href="https://leetcode.com/problems/bitwise-and-of-numbers-range/">
 * here</a>.
 *
 * @param[in] m: Lower range
 * @param[in] n: Upper range
 * @returns The bitwise AND of all numbers in this range, inclusive.
 */
int range_bitwise_and(int m, int n);

int main(int argc, char const *argv[]) {
    uint32_t m = 5;
    uint32_t n = 7;
    uint32_t solution = 4;

    assert(range_bitwise_and(m, n) == solution);

    return 0;
}

int range_bitwise_and(int m, int n) {
    while (m < n) {
        n &= (n - 1);
    }

    return n;
}
