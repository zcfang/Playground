#include <assert.h>

/**
 * Problem from LeetCode 7: Reverse Integer. You can find the problem
 * <a href="https://leetcode.com/problems/reverse-integer/">
 * here</a>.
 *
 * @param[in] x: A number
 * @returns An int where the input digits are reversed
 */
int reverse(int x)

int main(int argc, char const *argv[]) {
    int test_case_1 = 123;
    int test_case_2 = -123;
    int test_case_3 = 120;

    assert(reverse(test_case_1) == 321);
    assert(reverse(test_case_2) == -321);
    assert(reverse(test_case_3) == 21);

    return 0;
}

int reverse(int x) {
    int result = 0;
        
    while (x) {
        int digit = x % 10;
        x /= 10;
        
        if (result > INT_MAX / 10 ||
           (result == INT_MAX /10 && digit > 7)) return 0;
        if (result < INT_MIN / 10 ||
           (result == INT_MIN /10 && digit < -8)) return 0;
        
        result = result * 10 + digit;
    }
        
    return result;
}