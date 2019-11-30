#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 36: Valid Sudoku.
 * You can find the problem
 * <a href="https://leetcode.com/problems/valid-sudoku/">
 * here</a>.
 *
 * @param[in] board: A representation of a sudoku board
 * @returns Whether the sudoku board is valid
 */
bool is_valid_sudoku(std::vector<std::vector<char>> &board);

int main(int argc, char const *argv[]) {
    std::vector<std::vector<char>> test_case_1 = \
    {{'5','3','.','.','7','.','.','.','.'},
     {'6','.','.','1','9','5','.','.','.'},
     {'.','9','8','.','.','.','.','6','.'},
     {'8','.','.','.','6','.','.','.','3'},
     {'4','.','.','8','.','3','.','.','1'},
     {'7','.','.','.','2','.','.','.','6'},
     {'.','6','.','.','.','.','2','8','.'},
     {'.','.','.','4','1','9','.','.','5'},
     {'.','.','.','.','8','.','.','7','9'}};

    assert(is_valid_sudoku(test_case_1));

    return 0;
}

bool is_valid_sudoku(std::vector<std::vector<char>> &board) {
    std::unordered_map<int, std::unordered_set<char>> check_row;
    std::unordered_map<int, std::unordered_set<char>> check_col;
    std::unordered_map<int, std::unordered_set<char>> check_sqr;
    
    for (std::size_t row = 0; row < board.size(); row++) {
        for (std::size_t col = 0; col < board[row].size(); col++) {
            char value = board[row][col];
            if (value != '.') {
                int index = (row / 3) * 3 + col / 3;
                if (check_row[row].count(value)) {
                    return false;
                } else {
                    check_row[row].insert(value);
                }
                if (check_col[col].count(value)) {
                    return false;
                } else {
                    check_col[col].insert(value);
                }
                if (check_sqr[index].count(value)) {
                    return false;
                } else {
                    check_sqr[index].insert(value);
                }
            }
        }
    }

    return true;
}
