#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 922: Sort Array By Parity II. You can find the
 * problem <a href="https://leetcode.com/problems/sort-array-by-parity-ii/">
 * here</a>.
 *
 * @param[in] A: A vector of numbers
 * @returns An array so that whenever A[i] is odd, i is odd; and whenever A[i]
 * is even, i is even.
 */
std::vector<int> sort_array_by_parity_ii(std::vector<int> &A);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{2,4,1,1,1,3,4,3,2,0};
    std::vector<int> solution{2,1,0,1,4,3,4,3,2,1};

    assert(sort_array_by_parity_ii(test_case_1) == solution);

    return 0;
}

std::vector<int> sort_array_by_parity_ii(std::vector<int> &A) {
    int i = 0;
    int odd = A.size() - 1;
    int even = A.size() - 2;

    while (i < odd || i < even) {
        if (i % 2 != A[i] % 2) {
            int temp = A[i];
            if (i % 2 && !(A[odd] % 2) && odd % 2) {
                A[i] = A[even];
                A[even] = temp;
            } else if (!(i % 2) && A[even] % 2 && !(even % 2)) {
                A[i] = A[odd];
                A[odd] = temp;
            }
        }

        if (i % 2 == A[i] % 2) i++;
        if (A[odd] % 2) odd = odd - 2 > 0 ? odd - 2 : 0;
        if (!(A[even] % 2)) even = even -2 > 0 ? even - 2 : 0;
    }
    
    return A;
}
