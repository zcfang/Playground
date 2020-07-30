#include <assert.h>

/**
 * Problem from LeetCode 9: Palindrome Number. You can find the problem
 * <a href="https://leetcode.com/problems/palindrome-number/">
 * here</a>.
 *
 * @param[in] x: A number
 * @returns A boolean indicating whether `x` is a palindrome
 */
bool is_palindrome(int x);

int main(int argc, char const *argv[]) {
    int test_case_1 = 121;

    assert(is_palindrome(test_case_1));

    return 0;
}

bool is_palindrome(int x) {
    if (x < 0 || (!(x % 10) && x != 0)) return false;
    int num = 0;

    while (x > num) {
        num = (num * 10) + (x % 10);
        x /= 10;
    }

    return ((x == num) || (x == num / 10));
}
