#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 204: Count Primes. You can find the problem
 * <a href="https://leetcode.com/problems/count-primes/">
 * here</a>.
 *
 * @param[in] n: An integer
 * @returns The number of prime numbers less than a non-negative number, n.
 */
int count_primes(int n);

int main(int argc, char const *argv[]) {
    int test_case_0 = 0;
    int test_case_1 = 1;
    int test_case_2 = 2;
    int test_case_3 = 3;
    int test_case_4 = 4;
    int test_case_5 = 5;

    assert(count_primes(test_case_0) == 0);
    assert(count_primes(test_case_1) == 0);
    assert(count_primes(test_case_2) == 0);
    assert(count_primes(test_case_3) == 1);
    assert(count_primes(test_case_4) == 2);
    assert(count_primes(test_case_5) == 2);
    return 0;
}

int count_primes(int n) {
    if (n < 3) return 0;
    std::vector<int> prime(n, 1);
    int start = 2;
    int total = 0;

    prime[0] = 0;
    prime[1] = 0;

    while (start) {
        for (std::size_t i = start * 2; i < n; i += start) {
            prime[i] = 0;
        }
        for (std::size_t j = start; j < n; j++) {
            if (j != start && prime[j]) {
                start = j;
                break;
            } else if (j == n - 1) {
                start = 0;
            }
        }
    }
    
    for (const int value : prime) {
        total += value;
    }

    return total;
}
