#include <vector>
#include <queue>
#include <assert.h>

/**
 * Problem from LeetCode 286: Walls and Gates. You can find the problem
 * <a href="https://leetcode.com/problems/walls-and-gates/">
 * here</a>.
 *
 * @param[in,out] rooms: A m x n 2D grid initialized with three possible
 * values, -1, 0, INF. Fill each empty room with the distance to its
 * nearest gate. If it is impossible to reach a gate, it should be filled with
 * INF
 */
void walls_and_gates(std::vector<std::vector<int>> &rooms);

/**
 * Given a 2D map of rooms, walls, and gates, this method fills each empty room
 * with the distance to its nearest gate
 *
 * @param[in,out] rooms: A m x n 2D grid initialized with three possible
 * values, -1, 0, INF. Fill each empty room with the distance to its
 * nearest gate. If it is impossible to reach a gate, it should be filled with
 * INF
 */
void fill_empty_rooms(int row, int col, std::vector<std::vector<int>> &rooms);

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> test_case_1 = {
        {INT_MAX, -1, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, -1},
        {INT_MAX, -1, INT_MAX, -1},
        {0, -1, INT_MAX, INT_MAX}};
    std::vector<std::vector<int>> solution = {{3, -1, 0, 1},
                                              {2, 2, 1, -1},
                                              {1, -1, 2, -1},
                                              {0, -1, 3, 4}};
    walls_and_gates(test_case_1);
    assert(test_case_1 == solution);

    return 0;
}

void fill_empty_rooms(int row, int col, std::vector<std::vector<int>> &rooms) {
    std::queue<std::pair<int, int>> explore;
    explore.push({row, col});

    while (!explore.empty()) {
        int r = explore.front().first;
        int c = explore.front().second;
        explore.pop();
        if (c - 1 >= 0 && rooms[r][c - 1] > rooms[r][c] + 1) {
            rooms[r][c - 1] = rooms[r][c] + 1;
            explore.push({r, c - 1});
        }
        if (c + 1 < rooms[0].size() && rooms[r][c + 1] >  rooms[r][c] + 1) {
            rooms[r][c + 1] = rooms[r][c] + 1;
            explore.push({r, c + 1});
        }
        if (r - 1 >= 0 && rooms[r - 1][c] > rooms[r][c] + 1) {
            rooms[r - 1][c] = rooms[r][c] + 1;
            explore.push({r - 1, c});
        }
        if (r + 1 < rooms.size() && rooms[r + 1][c] > rooms[r][c] + 1) {
            rooms[r + 1][c] = rooms[r][c] + 1;
            explore.push({r + 1, c});
        }
    }
}

void walls_and_gates(std::vector<std::vector<int>> &rooms) {
    for (std::size_t row = 0; row < rooms.size(); row++) {
        for (std::size_t col = 0; col < rooms[row].size(); col++) {
            if (rooms[row][col] == 0) {
                fill_empty_rooms(row, col, rooms);
            }
        }
    }
}
