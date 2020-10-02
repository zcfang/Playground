#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 915: Partition Array into Disjoint Intervals. You can
 * find the problem <a href="https://leetcode.com/problems/transpose-matrix/">
 * here</a>.
 *
 * @param[in] A: A vector of numbers
 * @returns The length of `left` after partitioning vector `A`
 */
int partition_disjoint(std::vector<int> &A);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1 = {5,0,3,8,6};
    int solution = 3;

    assert(partition_disjoint(test_case_1) == solution);

    return 0;
}

int partition_disjoint(std::vector<int> &A) {
    int output = 1;
    int max_left = A[0];
    int global_max = A[0];

    for (std::size_t i = 1; i < A.size(); i++) {
        global_max = std::max(global_max, A[i]);
        if (A[i] < max_left) {
            max_left = global_max;
            output = i + 1;
        }
    }

    return output;
}
