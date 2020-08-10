#include <vector>
#include <queue>
#include <assert.h>

/**
 * Problem from LeetCode 994: Rotting Oranges. You can find the problem
 * <a href="https://leetcode.com/problems/rotting-oranges/">
 * here</a>.
 *
 * @param[in] grid: A 2D grid where 0, 1, and 2 represents an empty cell, a
 * fresh orange, and a rotten orange respectively.
 * @returns The minimum number of minutes that must elapse until no cell has a
 * fresh orange.  If this is impossible, return -1 instead. 
 */
int oranges_rotting(std::vector<std::vector<int>> &grid);

/**
 * Given a 2D grid of fresh oranges, rotten oranges, and empty cells, this
 * function simulates rotten oranges infecting fresh oranges
 *
 * @param[in,out] rotten_orange: A queue of rotten oranges
 * @param[in] grid: A 2D grid where 0, 1, and 2 represents an empty cell, a
 * fresh orange, and a rotten orange respectively.
 */
void infect_orange(std::queue<std::pair<int, int>> &rotten_orange,
                   std::vector<std::vector<int>> &grid);

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> test_case_1 = {{2,1,1},
                                                 {1,1,0},
                                                 {0,1,1}};
    assert(oranges_rotting(test_case_1) == 4);

    return 0;
}

void infect_orange(std::queue<std::pair<int, int>> &rotten_orange,
                   std::vector<std::vector<int>> &grid) {
    std::vector<std::pair<int, int>> offsets = {{0, -1}, {0, 1},
                                                {-1, 0}, {1, 0}};
    std::queue<std::pair<int, int>> newly_infected;

    while (!rotten_orange.empty()) {
        std::pair<int, int> rotten = rotten_orange.front();
        int row = rotten.first;
        int col = rotten.second;
        rotten_orange.pop();
        for (const std::pair<int, int> offset : offsets) {
            if (col + offset.second >= 0 &&
                col + offset.second < grid[row].size() &&
                row + offset.first >= 0 &&
                row + offset.first < grid.size() &&
                grid[row + offset.first][col + offset.second] == 1) {
                newly_infected.push({row + offset.first, col + offset.second});
                grid[row + offset.first][col + offset.second] = 0;
            }
        }
    }
    rotten_orange = newly_infected;
}

int oranges_rotting(std::vector<std::vector<int>> &grid) {
    std::queue<std::pair<int, int>> rotten;
    int time = 0;

    for (std::size_t row = 0; row < grid.size(); row++) {
        for (std::size_t col = 0; col < grid[row].size(); col++) {
            if (grid[row][col] == 2) {
                rotten.push({row, col});
                grid[row][col] = 0;
            }
        }
    }
    while (!rotten.empty()) {
        infect_orange(rotten, grid);
        time++;
    }
    for (const std::vector<int> row : grid) {
        for (const int orange : row) {
            if (orange == 1) return -1;
        }
    }
    time = time ? time - 1 : time;

    return time;
}
