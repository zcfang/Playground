#include <cstddef>
#include <assert.h>

/**
 * Problem from LeetCode 1137: N-th Tribonacci Number. You can find the problem
 * <a href="https://leetcode.com/problems/n-th-tribonacci-number/">
 * here</a>.
 *
 * @param[in] n: The nth Tribonacci number
 * @returns The value of the nth Tribonacci number
 */
int tribonacci(int n);

int main(int argc, char const *argv[]) {
    int test_case_1 = 4;
    int test_case_2 = 8;

    assert(tribonacci(test_case_1) == 4);
    assert(tribonacci(test_case_2) == 44);

    return 0;
}

int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    
    int n_0 = 0;
    int n_1 = 1;
    int n_2 = 1;
    int n_3 = 0;

    for (std::size_t i = 3; i <= n; i++) {
        n_3 = n_0 + n_1 + n_2;
        n_0 = n_1;
        n_1 = n_2;
        n_2 = n_3;
    }
    
    return n_3;
}
