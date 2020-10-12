#include <vector>
#include <string>
#include <assert.h>

/**
 * Problem from LeetCode 1087: Brace Expansion. You can find the
 * problem
 * <a href="https://leetcode.com/problems/brace-expansion/">
 * here</a>.
 *
 * @param[in] S: A string representing a list of words
 * @returns All combinations of strings that can be formed from S
 */
std::vector<std::string> expand(std::string S);

/**
 * Return all combinations of strings that can be formed from `S` via
 * backtracking
 *
 * @param[in] index: Index of `parsed`
 * @param[in] word: A possible string combination of `S`
 * @param[in] parsed: Characters used to generate `word`;
 * @param[in,out] output: All combinations of strings that can be formed from
 * `S`
 */
void backtrack(int index, std::string &word, std::vector<std::string> &parsed,
               std::vector<std::string> &output);

int main(int argc, char const *argv[]) {
    std::string test_case_1 = "{a,b,c}d{e,f}";
    std::vector<std::string> solution{"ade", "adf", "bde",
                                      "bdf", "cde", "cdf"};

    assert(expand(test_case_1) == solution);

    return 0;
}

void backtrack(int index, std::string &word, std::vector<std::string> &parsed,
               std::vector<std::string> &output) {
    if (word.size() == parsed.size()) {
        output.push_back(word);
        return;
    }
    for (std::size_t i = 0; i < parsed[index].size(); i++) {
        word.push_back(parsed[index][i]);
        backtrack(index + 1, word, parsed, output);
        word.pop_back();
    }
}

std::vector<std::string> expand(std::string S) {
    std::vector<std::string> output;
    std::vector<std::string> parsed;
    std::string word = "";

    for (std::size_t i = 0; i < S.size(); i++) {
        if (S[i] == '{') {
            std::string token = "";
            while (S[++i] != '}') {
                if (std::isalpha(S[i])) {
                    token.push_back(S[i]);
                }
            }
            std::sort(token.begin(), token.end());
            parsed.push_back(token);
        } else {
            std::string token(1, S[i]);
            parsed.push_back(token);
        }
    }
    backtrack(0, word, parsed, output);

    return output;
}
