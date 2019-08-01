#include <vector>
#include <string>
#include <iostream>
#include <assert.h>

/**
 * Problem from LeetCode 8: String to Integer (atoi). You can find
 * the problem
 * <a href="https://leetcode.com/problems/string-to-integer-atoi/"> here</a>.
 *
 * @param[in] str: A string with words, whitespaces and/or numbers
 * @returns An integer that was once represented as a string in str
 */
int my_atoi(std::string str);

int main(int argc, char const *argv[]) {
    std::string test_case_1 = "42";
    std::string test_case_2 = "   -42";
    std::string test_case_3 = "4193 with words";
    std::string test_case_4 = "words and 987";
    std::string test_case_5 = "-91283472332";
    std::string test_case_6 = "-2147483648";
    std::string test_case_7 = "2147483648";

    assert(my_atoi(test_case_1) == 42);
    assert(my_atoi(test_case_2) == -42);
    assert(my_atoi(test_case_3) == 4193);
    assert(my_atoi(test_case_4) == 0);
    assert(my_atoi(test_case_5) == INT_MIN);
    assert(my_atoi(test_case_6) == -2147483648);
    assert(my_atoi(test_case_7) == 2147483647);

    return 0;
}

int my_atoi(std::string str) {
    int result = 0;
    bool start = false;
    bool end = false;
    char sign = '+';
    int digit;

    for (char value : str) {
        if (!start) {
            switch (value) {
                case '-':
                    sign = value;
                    start = true;
                    break;
                case '+':
                    sign = value;
                    start = true;
                    break;
                case ' ':
                    break;
                case '0' ... '9':
                    result = value - '0';
                    start = true;
                    break;
                default:
                    return result;
            }
        } else if (start && !end) {
            switch (value) {
                case '0' ... '9':
                    digit = (value -'0');
                    if (sign == '+') {
                        if (result > INT_MAX / 10 ||
                            (result == INT_MAX / 10 &&
                            (digit > 7))) return INT_MAX;
                        result = (result * 10) + digit;
                    } else {
                        if (result < INT_MIN / 10 ||
                            (result == INT_MIN / 10 &&
                            (digit > 8))) return INT_MIN;
                        result = (result * 10) - digit;
                    }
                    break;
                default:
                    end = true;
                    break;
            }
        }
        if (end) break;
    }

    return result;
}