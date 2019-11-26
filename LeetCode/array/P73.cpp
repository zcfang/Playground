#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 73: Set Matrix Zeroes. You can find the problem
 * <a href="https://leetcode.com/problems/set-matrix-zeroes/">
 * here</a>.
 *
 * @param[in] matrix: A m x n matrix
 */
void set_zeroes(std::vector<std::vector<int>> &matrix);

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> test_case_1{{1,1,1},
                                              {1,0,1},
                                              {1,1,1}};
    std::vector<std::vector<int>> solution_1{{1,0,1},
                                             {0,0,0},
                                             {1,0,1}};
    set_zeroes(test_case_1);
    assert(test_case_1 == solution_1);

    return 0;
}

void set_zeroes(std::vector<std::vector<int>> &matrix) {
    bool is_col = false;

    for (std::size_t row = 0; row < matrix.size(); row++) {
        if (!matrix[row][0]) is_col = true;
        for (std::size_t col = 1; col < matrix[row].size(); col++) {
            if (!matrix[row][col]) {
                matrix[row][0] = 0;
                matrix[0][col] = 0;
            }
        }
    }
    
    for (std::size_t row = 1; row < matrix.size(); row++) {
        for (std::size_t col = 1; col < matrix[row].size(); col++) {
            if (!matrix[row][0] || !matrix[0][col]) {
                matrix[row][col] = 0;
            }
        }
    }
    
    if (!matrix[0][0]) {
        for (std::size_t col = 0; col < matrix[0].size(); col++) {
            matrix[0][col] = 0;
        }
    }
    
    if (is_col) {
        for (std::size_t row = 0; row < matrix.size(); row++) {
            matrix[row][0] = 0;
        }
    }
}
