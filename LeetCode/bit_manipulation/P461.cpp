#include <assert.h>

/**
 * Problem from LeetCode 461: Hamming Distance. You can find the problem
 * <a href="https://leetcode.com/problems/hamming-distance/">
 * here</a>.
 *
 * @param[in] x: An integer
 * @param[in] y: An integer
 * @returns Total number of different bits between x and y
 */
int hamming_distance(int x, int y);

int main(int argc, char const *argv[]) {
    int x = 4;
    int y = 1;

    assert(hamming_distance(x, y) == 2);

    return 0;
}

int hamming_distance(int x, int y) {
    int diff_bits = x ^ y;
    int total = 0;

    while (diff_bits) {
        total++;
        diff_bits &= (diff_bits - 1);
    }

    return total;
}
