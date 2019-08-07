#include <assert.h>

/**
 * Problem from LeetCode 191: Number of 1 Bits. You can find the problem
 * <a href="https://leetcode.com/problems/number-of-1-bits/">
 * here</a>.
 *
 * @param[in] n: A 32 bit number
 * @returns The number of `1` bits in `n`
 */
int hamming_weight(uint32_t n);

int main(int argc, char const *argv[]) {
    uint32_t test_case_1 = 00000000000000000000000000001011;
    uint32_t test_case_2 = 00000000000000000000000010000000;

    assert(hamming_weight(test_case_1) == 3);
    assert(hamming_weight(test_case_2) == 1);

    return 0;
}

int hamming_weight(uint32_t n) {
    int count = 0;

    while (n) {
    	count++;
    	n &= (n - 1);
    }

    return count;
}