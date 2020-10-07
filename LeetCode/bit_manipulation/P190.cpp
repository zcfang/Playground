#include <assert.h>

/**
 * Problem from LeetCode 190: Reverse Bits. You can find the problem
 * <a href="https://leetcode.com/problems/reverse-bits/">
 * here</a>.
 *
 * @param[in] n: A 32 bit number
 * @returns A 32 bit number where the bits are reversed
 */
uint32_t reverse_bits(uint32_t n);

int main(int argc, char const *argv[]) {
    uint32_t test_case_1 = 43261596;
    uint32_t test_case_2 = 4294967293;

    assert(reverse_bits(test_case_1) == 964176192);
    assert(reverse_bits(test_case_2) == 3221225471);

    return 0;
}

uint32_t reverse_bits(uint32_t n) {
    uint32_t reverse = 0;
    for (size_t i = 0; i < 32; i++) {
        reverse = (reverse * 2) + (n % 2);
        n /= 2;
    }
    
    return reverse;
}
