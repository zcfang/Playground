#include <string>
#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 1427: Perform String Shifts. You can find the problem
 * <a href="https://leetcode.com/problems/perform-string-shifts/">
 * here</a>.
 *
 * @param[in] s: A string
 * @param[in] shift: A vector of right or left shifts
 * @returns String `s` shifted by `shift` amount
 */
std::string string_shift(std::string s, std::vector<std::vector<int>> &shift);

int main(int argc, char const *argv[]) {
    std::string test_case_1 = "abc";
    std::vector<std::vector<int>> shift = {{0, 1}, {1, 2}};
    std::string solution = "cab";

    assert(string_shift(test_case_1, shift) == solution);

    return 0;
}

std::string string_shift(std::string s, std::vector<std::vector<int>> &shift) {
    int amount = 0;
    std::string result = "";

    for (const std::vector<int> info : shift) {
        amount = info[0] ? amount + info[1] : amount - info[1];
    }
    amount = amount > 0 ? amount % s.size() : -(std::abs(amount) % s.size());
    if (amount > 0) {
        std::string first = s.substr(s.size() - amount);
        std::string second = s.substr(0, s.size() - amount);
        result = first + second;
    } else {
        amount = std::abs(amount);
        std::string first = s.substr(amount);
        std::string second = s.substr(0, amount);
        result = first + second;
    }

    return result;
}