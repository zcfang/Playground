#include <assert.h>

/**
 * Problem from LeetCode 258: Add Digits. You can find the problem
 * <a href="https://leetcode.com/problems/add-digits/">
 * here</a>.
 *
 * @param[in] n: An integer
 * @returns Repeatedly add all of n's digits until the result has only one
 * digit.
 */
int add_digits(int num);

int main(int argc, char const *argv[]) {
    int test_case_0 = 38;

    assert(add_digits(test_case_0) == 2);

    return 0;
}

int add_digits(int num) {
    if (!num) return num;
    else if (num % 9) return (num % 9);
    else return 9;
}
