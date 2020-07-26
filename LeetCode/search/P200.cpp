#include <vector>
#include <queue>
#include <assert.h>

/**
 * Problem from LeetCode 200: Number of Islands. You can find the problem
 * <a href="https://leetcode.com/problems/number-of-islands/">
 * here</a>.
 *
 * @param[in] grid: A 2D grid map of '1's (land) and '0's (water)
 * @returns The number of islands. An island is surrounded by water and is
 * formed by connecting adjacent lands horizontally or vertically. You may
 * assume all four edges of the grid are all surrounded by water.
 */
int num_islands(std::vector<std::vector<char>> &grid);

/**
 * Given a 2D map of islands and water and a starting point, this method
 * identify islands.
 *
 * @param[in] row: Row
 * @param[in] col: Column
 * @param[in,out]: A 2D map of islands and water 
 */
void find_island(int row, int col, std::vector<std::vector<char>> &grid);

int main(int argc, char const *argv[]) {
    std::vector<std::vector<char>> test_case_1 = {{'1','1','1','1','0'},
                                                  {'1','1','0','1','0'},
                                                  {'1','1','0','0','0'},
                                                  {'0','0','0','0','0'}};
    int solution = 1;

    assert(num_islands(test_case_1) == solution);

    return 0;
}

void find_island(int row, int col, std::vector<std::vector<char>> &grid) {
    std::queue<std::pair<int, int>> explore;
    explore.push({row, col});
    grid[row][col] = '0';

    while (!explore.empty()) {
        std::pair<int, int> node = explore.front();
        explore.pop();
        if (node.second - 1 >= 0 && grid[node.first][node.second - 1] == '1') {
            explore.push({node.first, node.second - 1});
            grid[node.first][node.second - 1] = '0';
        }
        if (node.second + 1 < grid[0].size() &&
            grid[node.first][node.second + 1] == '1') {
            explore.push({node.first, node.second + 1});
            grid[node.first][node.second + 1] = '0';
        }
        if (node.first - 1 >= 0 && grid[node.first - 1][node.second] == '1') {
            explore.push({node.first - 1, node.second});
            grid[node.first - 1][node.second] = '0';
        }
        if (node.first + 1 < grid.size() &&
            grid[node.first + 1][node.second] == '1') {
            explore.push({node.first + 1, node.second});
            grid[node.first + 1][node.second] = '0';
        }
    }
}

int num_islands(std::vector<std::vector<char>> &grid) {
    int count = 0;

    for (std::size_t row = 0; row < grid.size(); row++) {
        for (std::size_t col = 0; col < grid[row].size(); col++) {
            if (grid[row][col] == '1') {
                find_island(row, col, grid);
                count++;
            }
        }
    }

    return count;
}
