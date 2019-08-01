#include <math.h>
#include <assert.h>

/**
 * Problem from LeetCode 326: Power of Three. You can find the problem
 * <a href="https://leetcode.com/problems/power-of-three/">
 * here</a>.
 *
 * @param[in] n: An integer
 * @returns A boolean indicating whether n is a power of three
 */
bool is_power_of_three(int n);

int main(int argc, char const *argv[]) {
    int test_case_1 = 27;
    int test_case_2 = 0;
    int test_case_3 = 9;
    int test_case_4 = 45;
    int test_case_5 = 243;

    assert(is_power_of_three(test_case_1));
    assert(!is_power_of_three(test_case_2));
    assert(is_power_of_three(test_case_3));
    assert(!is_power_of_three(test_case_4));
    assert(is_power_of_three(test_case_5));
    return 0;
}

bool is_power_of_three(int n) {
    if (!n) return false;
    int exponent = log(n) / log(3);

    return (pow(3, exponent) == n || pow(3, exponent + 1) == n);
}