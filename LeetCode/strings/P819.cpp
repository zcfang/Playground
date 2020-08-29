#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <assert.h>

/**
 * Problem from LeetCode 819: Most Common Word. You can find
 * the problem
 * <a href="https://leetcode.com/problems/most-common-word/"> here</a>.
 *
 * @param[in] paragraph: A paragraph of words
 * @param[in] banned: A vector od banned words
 * @returns The most frequent word that is not banned
 */
std::string most_common_word(std::string paragraph,
                             std::vector<std::string> &banned);

int main(int argc, char const *argv[]) {
    std::string test_case_1 = 
    "Bob hit a ball, the hit BALL flew far after it was hit.";
    std::vector<std::string> banned = {"hit"};
    std::string solution = "ball";

    assert(most_common_word(test_case_1, banned) == solution);

    return 0;
}

std::string most_common_word(std::string paragraph,
                             std::vector<std::string> &banned) {
    std::unordered_map<std::string, int> histogram;
    std::unordered_set<std::string> banned_words;
    std::string output;
    std::string delimiter = " !?',;.";
    std::size_t start = 0;
    std::size_t end;
    int count = 0;

    while ((end = paragraph.find_first_of(delimiter, start)) !=
           std::string::npos) {
        std::string word = paragraph.substr(start, end - start);
        for (char &letter : word) letter = std::tolower(letter);
        histogram[word]++;
        start = paragraph.find_first_not_of(delimiter, end);
    }
    if (start != std::string::npos) {
        std::string word = paragraph.substr(start);
        for (char &letter : word) letter = std::tolower(letter);
        histogram[word]++;
    }
    for (const std::string word : banned) {
        banned_words.insert(word);
    }
    for (const std::pair<std::string, int> element : histogram) {
        if (!banned_words.count(element.first) && element.second > count) {
            count = element.second;
            output = element.first;
        }
    }

    return output;
}
