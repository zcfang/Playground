#include <string>
#include <assert.h>

/**
 * Problem from LeetCode 415: Add Strings. You can find the
 * problem <a href="https://leetcode.com/problems/add-strings/">
 * here</a>.
 *
 * @param[in] num1: A number
 * @param[in] num2: A number
 * @returns The sum of `num1` and `num2`.
 */
std::string add_strings(std::string num1, std::string num2);

int main(int argc, char const *argv[]) {
    assert(add_strings("15", "85") == "100");
    assert(add_strings("1", "15") == "16");

    return 0;
}

std::string add_strings(std::string num1, std::string num2) {
    std::string output = "";
    int index_1 = num1.size() - 1;
    int index_2 = num2.size() - 1;
    int carry = 0;

    while (index_1 >= 0 || index_2 >= 0) {
        int first = index_1 >= 0 ? num1[index_1] - '0' : 0;
        int second = index_2 >= 0 ? num2[index_2] - '0' : 0;
        int sum = first + second + carry;
        index_1--;
        index_2--;
        carry = sum / 10;
        sum %= 10;
        output.push_back(sum + '0');
    }
    if (carry) output.push_back(carry + '0');
    std::reverse(output.begin(), output.end());

    return output;
}
