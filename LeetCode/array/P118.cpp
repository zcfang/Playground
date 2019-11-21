#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 118: Pascal's Triangle. You can find the
 * problem
 * <a href="https://leetcode.com/problems/pascals-triangle/">
 * here</a>.
 *
 * @param[in] num_rows
 * @returns A vector of vectors representing Pascal's triangle
 */
std::vector<std::vector<int>> generate(int num_rows);

int main(int argc, char const *argv[]) {
    int test_case_1 = 3;
    std::vector<std::vector<int>> solution;
    std::vector<int> r0{1};
    std::vector<int> r1{1,1};
    std::vector<int> r2{1,2,1};

    solution.push_back(r0);
    solution.push_back(r1);
    solution.push_back(r2);
    assert(generate(test_case_1) == solution);

    return 0;
}

std::vector<std::vector<int>> generate(int num_rows) {
    std::vector<std::vector<int>> triangle;
    for (std::size_t i = 0; i < num_rows; i++) {
        std::vector<int> row;
        for (std::size_t j = 0; j < i; j++) {
            if (!j) {
                row.push_back(1);
            } else {
                int value = triangle[i - 1][j] + triangle[i - 1][j - 1];
                row.push_back(value);
            }
        }
        row.push_back(1);
        triangle.push_back(row);
    }
    
    return triangle;
}
