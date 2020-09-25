#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <assert.h>

/**
 * Problem from LeetCode 127: Word Ladder. You can find the
 * problem <a href="https://leetcode.com/problems/word-ladder/">
 * here</a>.
 *
 * @param[in] begin_word: Start word
 * @param[in] end_word: End word
 * @param[in] word_list: List of words
 * @returns The length of shortest transformation sequence from `begin_word` to
 * `end_word`, such that:
 * 1. Only one letter can be changed at a time.
 * 2. Each transformed word must exist in the word list.
 * Return 0 if there is no such transformation sequence.
 */
int ladder_length(std::string begin_word, std::string end_word,
                  std::vector<std::string> &list);

int main(int argc, char const *argv[]) {
    std::string begin_word = "hit";
    std::string end_word = "cog";
    std::vector<std::string> word_list = {"hot","dot","dog","lot","log","cog"};
    int solution = 5;

    assert(ladder_length(begin_word, end_word, word_list) == solution);

    return 0;
}

int ladder_length(std::string begin_word, std::string end_word,
                  std::vector<std::string> &list) {
    std::unordered_set<std::string> word_list(list.begin(), list.end());
    std::unordered_set<std::string> explored;
    std::queue<std::pair<std::string, int>> steps;

    if (!word_list.count(end_word))
        return 0;
    steps.push({begin_word, 1});
    explored.insert(begin_word);
    while (!steps.empty()) {
        std::string word = steps.front().first;
        int seq = steps.front().second;
        steps.pop();
        if (word == end_word) {
            return seq;
        }
        for (std::size_t i = 0; i < word.size(); i++) {
            std::string temp = word;
            for (char letter = 'a'; letter <= 'z'; letter++) {
                temp[i] = letter;
                if (word_list.count(temp) && !explored.count(temp)) {
                    steps.push({temp, seq + 1});
                    explored.insert(temp);
                }
            }
        }
    }

    return 0;
}
