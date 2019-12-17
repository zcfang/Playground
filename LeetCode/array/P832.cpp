#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 832: Flipping an Image. You can find the problem
 * <a href="https://leetcode.com/problems/flipping-an-image/">
 * here</a>.
 *
 * @param[in] A: A binary image
 * @returns An image flipped horizontally and inverted
 */
std::vector<std::vector<int>> flip_and_invert_image(
std::vector<std::vector<int>> &A);

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> test_case_1{{1,1,0},{1,0,1},{0,0,0}};
    std::vector<std::vector<int>> solution_1{{1,0,0},{0,1,0},{1,1,1}};

    assert(flip_and_invert_image(test_case_1) == solution_1);

    return 0;
}

std::vector<std::vector<int>> flip_and_invert_image(
std::vector<std::vector<int>> &A) {
    int col_size = A[0].size();
    for (std::size_t row = 0; row < A.size(); row++) {
        for (std::size_t col = 0; col < (col_size + 1) / 2; col++) {
            int tmp = !A[row][col];
            A[row][col] = !A[row][col_size - col - 1];
            A[row][col_size - col - 1] = tmp;
        }
    }
    
    return A;
}
