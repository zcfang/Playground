#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 64: Minimum Path Sum. You can find the problem
 * <a href="https://leetcode.com/problems/minimum-path-sum/">
 * here</a>.
 *
 * @param[in] grid: A m x n grid filled with non-negative numbers
 * @returns A path from top left to bottom right which minimizes the sum of all
 * numbers along its path.
 */
int min_path_sum(std::vector<std::vector<int>> &grid);

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> test_case_1 = {{1,3,1},
                                                 {1,5,1},
                                                 {4,2,1}};

    assert(min_path_sum(test_case_1) == 7);

    return 0;
}

int min_path_sum(std::vector<std::vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            int right = col - 1 >= 0 ? grid[row][col - 1] : -1;
            int up = row - 1 >= 0 ? grid[row - 1][col] : -1;
            if (right >= 0 && up < 0) {
                grid[row][col] += right;
            } else if (right < 0 && up >= 0) {
                grid[row][col] += up;
            } else if (right >= 0 && up >= 0) {
                grid[row][col] += std::min(right, up);
            }
        }
    }

    return grid[m - 1][n - 1];
}
