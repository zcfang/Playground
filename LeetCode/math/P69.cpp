#include <math.h>
#include <assert.h>

/**
 * Problem from LeetCode 69: Sqrt(x). You can find the problem
 * <a href="https://leetcode.com/problems/sqrtx/">
 * here</a>.
 *
 * @param[in] n: An integer
 * @returns The integer value of the square root of x
 */
int my_sqrt(int x);

int main(int argc, char const *argv[]) {
    int test_case_1 = 4;
    int test_case_2 = 8;

    assert(my_sqrt(test_case_1) == 2);
    assert(my_sqrt(test_case_2) == 2);

    return 0;
}

int my_sqrt(int x) {
    return ((int) pow(10, log10(x)/2));
}
