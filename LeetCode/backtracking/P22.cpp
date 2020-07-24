#include <vector>
#include <string>
#include <assert.h>

/**
 * Problem from LeetCode 22: Generate Parentheses. You can find the
 * problem
 * <a href="https://leetcode.com/problems/generate-parentheses/">
 * here</a>.
 *
 * @param[in] n: n pair(s) of parentheses
 * @returns All combinations of n well-formed parentheses.
 */
std::vector<std::string> generate_parenthesis(int n);

/**
 * Return all combinations of `n` well-formed parentheses by backtracking to
 * original state after computing a particular permutation.
 *
 * @param[in] n: n pair(s) of parentheses
 * @param[in] open_count: Count of open parentheses
 * @param[in] close_count: Count of close parentheses
 * @param[in] parentheses: A string containing parentheses
 * @param[in,out] output: All combinations of n well-formed parentheses
 */
void backtrack(int n, int open_count, int close_count,
               std::string parentheses, std::vector<std::string> &output);

int main(int argc, char const *argv[]) {
    int test_case_1 = 3;
    std::vector<std::string> solution{"((()))","(()())","(())()",
                                      "()(())","()()()"};

    assert(generate_parenthesis(test_case_1) == solution);

    return 0;
}

void backtrack(int n, int open_count, int close_count,
               std::string parentheses, std::vector<std::string> &output) {
    if (parentheses.size() == 2 * n) {
        output.push_back(parentheses);
        return;
    }
    if (open_count < n) {
        parentheses.push_back('(');
        backtrack(n, open_count + 1, close_count, parentheses, output);
        parentheses.pop_back();
    }
    if (open_count > close_count) {
        parentheses.push_back(')');
        backtrack(n, open_count, close_count + 1, parentheses, output);
        parentheses.pop_back();
    }
}

std::vector<std::string> generate_parenthesis(int n) {
    int open_count = 0;
    int close_count = 0;
    std::string parentheses = "";
    std::vector<std::string> output;

    backtrack(n, open_count, close_count, parentheses, output);

    return output;
}
