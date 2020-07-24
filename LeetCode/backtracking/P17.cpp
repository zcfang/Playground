#include <vector>
#include <string>
#include <map>
#include <assert.h>

std::map<char, std::string> PHONE_LETTER = {{'2', "abc"},
                                            {'3', "def"},
                                            {'4', "ghi"},
                                            {'5', "jkl"},
                                            {'6', "mno"},
                                            {'7', "pqrs"},
                                            {'8', "tuv"},
                                            {'9', "wxyz"}};
/**
 * Problem from LeetCode 17: Letter Combinations of a Phone Number.
 * You can find the problem
 * <a href="https://leetcode.com/problems/letter-combinations-of-a-phone-number/">
 * here</a>.
 *
 * @param[in] digits: A string containing digits from 2-9 inclusive
 * @returns All possible letter combinations that the number could represent.
 */
std::vector<std::string> letter_combinations(std::string digits);

/**
 * Return all letter combinations that `digits` could represent by backtracking
 * to original state after computing a particular combination.
 *
 * @param[in] index: Index of `digits`
 * @param[in] digits: A string containing digits from 2-9 inclusive
 * @param[in] combine: Letter combination of what `digits` could represent
 * @param[in,out] output: All possible letter combinations that the number
 * could represent.
 */
void generate(int index, std::string digits, std::string combine,
              std::vector<std::string> &output);

int main(int argc, char const *argv[]) {
    std::string test_case_1 = "23";
    std::vector<std::string> solution{"ad", "ae", "af",
                                      "bd", "be", "bf",
                                      "cd", "ce", "cf"};

    assert(letter_combinations(test_case_1) == solution);

    return 0;
}

void generate(int index, std::string digits, std::string combine,
              std::vector<std::string> &output) {
    std::string letters = PHONE_LETTER[digits[index]];
    for (const char letter : letters) {
        combine.push_back(letter);
        if (index + 1 < digits.size()) {
            generate(index + 1, digits, combine, output);
        }
        if (combine.size() == digits.size()) {
            output.push_back(combine);
        }
        combine.pop_back();
    }
}

std::vector<std::string> letter_combinations(std::string digits) {
    int index = 0;
    std::string combine = "";
    std::vector<std::string> output;

    generate(index, digits, combine, output);

    return output;
}
