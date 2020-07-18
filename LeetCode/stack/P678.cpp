#include <stack>
#include <string>
#include <assert.h>

/**
 * Problem from LeetCode 678: Valid Parenthesis String. You can find the
 * problem
 * <a href="https://leetcode.com/problems/valid-parenthesis-string/">
 * here</a>.
 *
 * @param[in] s: A string containing only three types of characters: '(', ')'
 * and '*'
 * @returns A boolean to check whether this string is valid. 
 */
bool check_valid_string(std::string s);

int main(int argc, char const *argv[]) {
    std::string test_case_1 = "(*))";

    assert(check_valid_string(test_case_1));

    return 0;
}

bool check_valid_string(std::string s) {
    std::stack<int> open_bracket;
    std::stack<int> star;
    
    for (std::size_t i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            open_bracket.push(i);
        } else if (s[i] == '*') {
            star.push(i);
        } else if (s[i] == ')' && !open_bracket.empty()) {
            open_bracket.pop();
        } else if (s[i] == ')' && !star.empty()) {
            star.pop();
        } else {
            return false;
        }
    }
    while (!open_bracket.empty() && !star.empty() &&
           star.top() > open_bracket.top()) {
        star.pop();
        open_bracket.pop();
    }

    return open_bracket.empty();
}
