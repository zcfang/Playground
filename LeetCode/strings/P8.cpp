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
    std::string clean_str;
        std::string whitelist = "-0123456789";
        std::size_t start = str.find_first_of(whitelist);
        std::size_t end = str.find_first_not_of(whitelist, start);
        int output = 0;
        bool negative;

        if (end - start == 0) {
            clean_str = "";
        } else if ((str[str.find_first_not_of(" ")] == '-' &&
                    std::isdigit(str[str.find_first_not_of(" ") + 1])) ||
                   (str[str.find_first_not_of(" ")] == '+' &&
                    std::isdigit(str[str.find_first_not_of(" ") + 1])) ||
                   std::isdigit(str[str.find_first_not_of(" ")])) {
            clean_str = str.substr(start, end - start);
        } else {
            clean_str = "";
        }
        negative = (clean_str.size() > 0) && (clean_str[0] == '-');
        int i = std::isdigit(clean_str[0]) ? 0 : 1;
        for (; i < clean_str.size(); i++) {
            int digit = clean_str[i] - '0';
            digit = negative ? -digit : digit;
            if (!std::isdigit(clean_str[i])) return output;
            if (output > INT_MAX / 10 ||
                (output == INT_MAX / 10 && digit > 7)) return INT_MAX;
            if (output < INT_MIN / 10 ||
                (output == INT_MIN / 10 && digit < -8)) return INT_MIN;
            output = output * 10 + digit;
        }

        return output;
}
