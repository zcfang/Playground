#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 1099: Two Sum Less Than K. You can find the
 * problem
 * <a href="https://leetcode.com/problems/two-sum-less-than-k/">
 * here</a>.
 *
 * @param[in] A: A vector of numbers
 * @param[in] K: A number
 * @returns She maximum S such that there exists i < j with A[i] + A[j] = S
 * and S < K. If no i, j exist satisfying this equation, return -1.
 */
int two_sum_less_than_k(std::vector<int>& A, int K);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1 = {34,23,1,24,75,33,54,8};
    int K = 60;
    int solution = 58;

    assert(two_sum_less_than_k(test_case_1, K) == solution);

    return 0;
}

int two_sum_less_than_k(std::vector<int>& A, int K) {
    int output = -1;
    int first = 0;
    int sec = A.size() - 1;

    std::sort(A.begin(), A.end());
    while (first < sec) {
        if (A[first] + A[sec] >= K) {
            sec--;
        } else {
            output = std::max(output, A[first] + A[sec]);
            first++;
        }
    }

    return output;
}
