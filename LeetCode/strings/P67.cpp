#include <string>
#include <assert.h>

/**
 * Problem from LeetCode 67: Add Binary. You can find the
 * problem <a href="https://leetcode.com/problems/add-binary/">
 * here</a>.
 *
 * @param[in] a: A binary number
 * @param[in] b: A binary number
 * @returns The sum of `a` and `b`.
 */
std::string add_binary(std::string a, std::string b);

int main(int argc, char const *argv[]) {
    assert(add_binary("11", "1") == "100");
    assert(add_binary("1010", "1011") == "10101");

    return 0;
}

std::string add_binary(std::string a, std::string b) {
    std::string output = "";
    int index_a = a.size() - 1;
    int index_b = b.size() - 1;
    int carry = 0;

    while (index_a >= 0 || index_b >= 0) {
        int first = index_a >= 0 ? a[index_a] - '0' : 0;
        int second = index_b >= 0 ? b[index_b] - '0' : 0;
        int sum = first + second + carry;
        index_a--;
        index_b--;
        carry = sum / 2;
        sum %= 2;
        output.push_back(sum + '0');
    }
    if (carry) output.push_back(carry + '0');
    std::reverse(output.begin(), output.end());

    return output;
}
