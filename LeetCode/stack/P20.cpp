#include <stack>
#include <string>
#include <assert.h>

/**
 * Problem from LeetCode 20: Valid Parentheses. You can find the problem
 * <a href="https://leetcode.com/problems/valid-parentheses/">
 * here</a>.
 *
 * @param[in] n: A string with parenthesis characters
 * @returns A boolean indicating if the parenthesis characters are open and
 * closed in the correct order
 */
bool is_valid(std::string s);

int main(int argc, char const *argv[]) {
    std::string test_case_1 = "()";
    std::string test_case_2 = "(]";

    assert(is_valid(test_case_1));
    assert(!is_valid(test_case_2));

    return 0;
}

bool is_valid(std::string s) {
    std::stack<char> parentheses;
    
    for (char value : s) {
        switch (value) {
            case '(':
            case '{':
            case '[':
                parentheses.push(value);
                break;
            case ')':
                if (parentheses.empty()) return false;
                else if (parentheses.top() == '(') parentheses.pop();
                else return false;
                break;
            case '}':
                if (parentheses.empty()) return false;
                else if (parentheses.top() == '{') parentheses.pop();
                else return false;
                break;
            case ']':
                if (parentheses.empty()) return false;
                else if (parentheses.top() == '[') parentheses.pop();
                else return false;
                break;
        }
    }

    return parentheses.empty();
}
