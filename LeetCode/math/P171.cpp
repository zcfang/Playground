#include <string>
#include <assert.h>

/**
 * Problem from LeetCode 171: Excel Sheet Column Number You can find the
 * problem
 * <a href="https://leetcode.com/problems/excel-sheet-column-number/">
 * here</a>.
 *
 * @param[in] n: A number
 * @returns Given an integer number n, return the difference between the
 * product of its digits and the sum of its digits.
 */
int title_to_number(std::string s);

int main(int argc, char const *argv[]) {
    std::string test_case_1 = "ZY";

    assert(title_to_number(test_case_1) == 701);

    return 0;
}

int title_to_number(std::string s) {
    int number = 0;

    for (const int letter : s) {
        number *= 26;
        number += letter - 'A' + 1;
    }

    return number;
}
