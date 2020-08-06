#include <vector>
#include <string>
#include <assert.h>

/**
 * Problem from LeetCode 79: Word Search. You can find the
 * problem
 * <a href="https://leetcode.com/problems/word-search/">
 * here</a>.
 *
 * @param[in] board: A 2D board of letters
 * @param[in] word: A word
 * @returns A boolean of whether `word` can be found within `board`
 */
bool exist(std::vector<std::vector<char>> &board, std::string word);

/**
 * Given a starting point, this method tries to find `word` in `board.` If
 * `word` is found in `board`, the result is outputted in `output.` 
 *
 * @param[in] row: Row index
 * @param[in] col: Column index
 * @param[in,out] output: Matched string
 * @param[in] word: Word to search for in `board` 
 * @param[in,out] board: A 2D board of letters
 */
void find_word(int row, int col, std::string &output, std::string word,
               std::vector<std::vector<char>> &board);

int main(int argc, char const *argv[]) {
    std::vector<std::vector<char>> test_case_1{{'A','B','C','E'},
                                               {'S','F','C','S'},
                                               {'A','D','E','E'}};
    std::string word = "ABCCED";

    assert(exist(test_case_1, word));

    return 0;
}

void find_word(int row, int col, std::string &output, std::string word,
               std::vector<std::vector<char>> &board) {
    output.push_back(board[row][col]);
    board[row][col] = '#';
    char next_letter = word[output.size()];
    if (col - 1 >= 0 && board[row][col - 1] == next_letter) {
        find_word(row, col - 1, output, word, board);
        if (output == word) return;
        board[row][col - 1] = output.back();
        output.pop_back();
    }
    if (col + 1 < board[row].size() && board[row][col + 1] == next_letter) {
        find_word(row, col + 1, output, word, board);
        if (output == word) return;
        board[row][col + 1] = output.back();
        output.pop_back();
    }
    if (row - 1 >= 0 && board[row - 1][col] == next_letter) {
        find_word(row - 1, col, output, word, board);
        if (output == word) return;
        board[row - 1][col] = output.back();
        output.pop_back();
    }
    if (row + 1 < board.size() && board[row + 1][col] == next_letter) {
        find_word(row + 1, col, output, word, board);
        if (output == word) return;
        board[row + 1][col] = output.back();
        output.pop_back();
    }
    board[row][col] = output.back();
}

bool exist(std::vector<std::vector<char>> &board, std::string word) {
    for (std::size_t row = 0; row < board.size(); row++) {
        for (std::size_t col = 0; col < board[row].size(); col++) {
            if (board[row][col] == word[0]) {
                std::string output = "";
                find_word(row, col, output, word, board);
                if (output == word) {
                    return true;
                }
            }
        }
    }

    return false;
}
