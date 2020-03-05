#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 463: Island Perimeter. You can find the problem
 * <a href="https://leetcode.com/problems/island-perimeter/">
 * here</a>.
 *
 * @param[in] grid: A 2D array where 1 represents land and 0 represents water.
 * @returns The perimeter of islands in grid
 */
int island_perimeter(std::vector<std::vector<int>> &grid);

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> test_case_1{{0,1,0,0},
                                              {1,1,1,0},
                                              {0,1,0,0},
                                              {1,1,0,0}};

    assert(island_perimeter(test_case_1) == 16);

    return 0;
}

int island_perimeter(std::vector<std::vector<int>> &grid) {
    int perimeter = 0;

    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[row].size(); col++) {
            if (grid[row][col]) {
                if (col - 1 < 0) perimeter++;
                else if (!grid[row][col - 1]) perimeter++;
                if (col + 1 == grid[row].size()) perimeter++;
                else if (!grid[row][col + 1]) perimeter++;
                if (row - 1 < 0) perimeter++;
                else if (!grid[row - 1][col]) perimeter++;
                if (row + 1 == grid.size()) perimeter++;
                else if (!grid[row + 1][col]) perimeter++;
            }
        }
    }
    return perimeter;
}
