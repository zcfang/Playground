#include <assert.h>

/**
 * Problem from LeetCode 1281: Subtract the Product and Sum of Digits of an
 * Integer You can find the problem
 * <a href="https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/">
 * here</a>.
 *
 * @param[in] n: A number
 * @returns Given an integer number n, return the difference between the
 * product of its digits and the sum of its digits.
 */
int subtract_product_and_sum(int n);

int main(int argc, char const *argv[]) {
    int n = 234;

    assert(subtract_product_and_sum(n) == 15);

    return 0;
}

int subtract_product_and_sum(int n) {
    int product = 1;
    int sum = 0;
    
    while (n) {
        int digit = n % 10;
        n /= 10;
        product *= digit;
        sum += digit;
    }
    
    return product - sum;
}