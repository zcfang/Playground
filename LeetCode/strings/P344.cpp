#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 344: Reverse String. You can find
 * the problem
 * <a href="https://leetcode.com/problems/reverse-string/"> here</a>.
 *
 * @param[in] prices: A vector of characters
 */
void reverse_string(std::vector<char> &s);

int main(int argc, char const *argv[]) {
    std::vector<char> test_case_1{"h","e","l","l","o"};
    std::vector<char> test_case_2{"H","a","n","n","a","h"};

    return 0;
}

void reverse_string(std::vector<char> &s) {
    std::size_t n = s.size() / 2;
    std::size_t l = s.size();
    for (std::size_t i = 0; i < n; i++) {
        char front = s[i];
        char back = s[l - i - 1];
        s[i] = back;
        s[l - i - 1] = front;
    }
}