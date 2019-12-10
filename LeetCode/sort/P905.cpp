#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 905: Sort Array By Parity. You can find the
 * problem <a href="https://leetcode.com/problems/sort-array-by-parity/">
 * here</a>.
 *
 * @param[in] A: A vector of numbers
 * @returns An array consisting of all the even elements of A, followed by all
 * the odd elements of A.
 */
std::vector<int> sort_array_by_parity(std::vector<int> &A);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{3,1,2,4};
    std::vector<int> solution{4,2,1,3};

    assert(sort_array_by_parity(test_case_1) == solution);

    return 0;
}

std::vector<int> sort_array_by_parity(std::vector<int> &A) {
    int i = 0;
    int j = A.size() - 1;

    while (i < j) {
        if (A[i] % 2) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        if (!(A[i] % 2)) i++;
        if (A[j] % 2) j--;
    }

    return A;
}
