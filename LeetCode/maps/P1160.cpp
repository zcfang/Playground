#include <string>
#include <vector>
#include <unordered_map>
#include <assert.h>

/**
 * Problem from LeetCode 1160: Find Words That Can Be Formed by Characters.
 * You can find the problem
 * <a href="https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/">
 * here</a>.
 *
 * @param[in] words: A vector of words
 * @param[in] chars: A string of characters
 * @returns A string is good if it can be formed by characters from chars
 * (each character can only be used once). Return the sum of lengths of all
 * good strings in words.
 */
int count_characters(std::vector<std::string> &words, std::string chars);

int main(int argc, char const *argv[]) {
    std::vector<std::string> words = {"cat","bt","hat","tree"};
    std::string chars = "atach";

    assert(count_characters(words, chars) == 6);

    return 0;
}

int count_characters(std::vector<std::string> &words, std::string chars) {
    int output = 0;
    std::unordered_map<char, int> char_count;

    for (const char character : chars) {
        char_count[character]++;
    }

    for (const std::string word : words) {
        std::unordered_map<char, int> letters = char_count;
        for (std::size_t i = 0; i < word.size(); i++) {
            if (!letters.count(word[i])) {
                break;
            } else if (letters[word[i]] == 0) {
                break;
            } else if (i == word.size() - 1) {
                output += word.size();
            } else {
                letters[word[i]]--;
            }
        }
        letters = char_count;
    }
    
    return output;
}
