#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 867: Transpose Matrix. You can find the
 problem <a href="https://leetcode.com/problems/transpose-matrix/">
 * here</a>.
 *
 * @param[in] A: matrix
 * @returns Input matrix transposed
 */
std::vector<std::vector<int>> transpose(std::vector<std::vector<int>> &A);

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> test_case_1 = {{1,2,3},{4,5,6},{7,8,9}};
    std::vector<std::vector<int>> solution = {{1,4,7},{2,5,8},{3,6,9}};

    assert(transpose(test_case_1) == solution);

    return 0;
}

std::vector<std::vector<int>> transpose(std::vector<std::vector<int>> &A) {
    std::vector<std::vector<int>> output(A[0].size(),
                                         std::vector<int> (A.size(), 0));
    for (std::size_t row = 0; row < A.size(); row++) {
        for (std::size_t col = 0; col < A[0].size(); col++) {
            output[col][row] = A[row][col];
        }
    }
    
    return output;
}
