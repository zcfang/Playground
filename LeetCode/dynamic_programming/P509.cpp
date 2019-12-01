#include <cstddef>
#include <assert.h>

/**
 * Problem from LeetCode 509: Fibonacci Number. You can find the problem
 * <a href="https://leetcode.com/problems/fibonacci-number/">
 * here</a>.
 *
 * @param[in] N: Fibonacci index
 * @returns Fibonacci value at index N
 */
int fib(int N);

int main(int argc, char const *argv[]) {
    int test_case_1 = 4;

    assert(fib(test_case_1) == 3);

    return 0;
}

int fib(int N) {
    if (N == 0) return 0;
    if (N == 1) return 1;
    int n_1 = 1;
    int n_2 = 0;
    int n;
    
    for (std::size_t i = 2; i <= N; i++) {
        n = n_1 + n_2;
        n_2 = n_1;
        n_1 = n;
    }
    return n;
}
