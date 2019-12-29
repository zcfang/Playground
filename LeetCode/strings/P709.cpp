#include <string>
#include <assert.h>

/**
 * Problem from LeetCode 709: To Lower Case. You can find the problem
 * <a href="https://leetcode.com/problems/to-lower-case/">
 * here</a>.
 *
 * @param[in] str: A string
 * @returns Lowercase version of input string
 */
std::string to_lower_case(std::string str);

int main(int argc, char const *argv[]) {
    std::string test_case_1 = "Hello";

    assert(to_lower_case(test_case_1) == "hello");

    return 0;
}

std::string to_lower_case(std::string str) {
    for (std::size_t i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] -= ('A' - 'a');
        }
    }
    
    return str;
}