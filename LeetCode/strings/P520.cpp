#include <string>
#include <assert.h>

/**
 * Problem from LeetCode 520: Detect Capital. You can find the
 * problem <a href="https://leetcode.com/problems/detect-capital/">
 * here</a>.
 *
 * @param[in] word: A word
 * @returns Given a word, you need to judge whether the usage of capitals in it
 * is right or not.
 */
bool detect_capital_use(std::string word);

int main(int argc, char const *argv[]) {
    std::string test_case_1 = "USA";
    std::string test_case_2 = "FlaG";

    assert(detect_capital_use(test_case_1));
    assert(!detect_capital_use(test_case_2));

    return 0;
}

bool detect_capital_use(std::string word) {
    int upper_count = 0;
    bool first_up = std::isupper(word[0]);

    for (const char letter : word) {
        if (std::isupper(letter)) {
            upper_count++;
        }
    }

    return upper_count == word.size() ||
           (first_up && upper_count == 1) ||
           !upper_count;
}
