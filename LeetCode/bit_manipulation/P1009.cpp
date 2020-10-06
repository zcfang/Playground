#include <math.h>
#include <assert.h>

/**
 * Problem from LeetCode 1009: Complement of Base 10 Integer. You can find the
 * problem
 * <a href="https://leetcode.com/problems/complement-of-base-10-integer/">
 * here</a>.
 *
 * @param[in] N: A 32 bit number
 * @returns Complement of N
 */
int bitwise_complement(int N);

int main(int argc, char const *argv[]) {
    int test_case_1 = 5;
    int test_case_2 = 7;
    int solution_1 = 2;
    int solution_2 = 0;

    assert(bitwise_complement(test_case_1) == solution_1);
    assert(bitwise_complement(test_case_2) == solution_2);

    return 0;
}

int bitwise_complement(int N) {
    if (!N) return 1;
    int k = (int) log2(N) + 1;
    int n = N;

    return ~N & ((1 << k) - 1);
}
