#include <string>
#include <map>
#include <utility>
#include <assert.h>

/**
 * Problem from LeetCode 409: Longest Palindrome. You can find the problem
 * <a href="https://leetcode.com/problems/longest-palindrome/">
 * here</a>.
 *
 * @param[in] s: A string of random letters with maximum of 1010 characters
 * @returns An int representing the maximum length palindrome you can create
 * with input s
 */
int longest_palindrome(std::string s);

int main(int argc, char const *argv[]) {
    std::string test_case_1 = "abccccdd";
    std::string test_case_2 = "Aa";

    assert(longest_palindrome(test_case_1) == 7);
    assert(longest_palindrome(test_case_2) == 1);

    return 0;
}

int longest_palindrome(std::string s) {
    bool odd = false;
    int length = 0;
    std::map<char, int> letters;
    
    for (const char letter : s) {
        if (letters.count(letter) > 0) {
            letters[letter] += 1;
        } else {
            letters[letter] = 1;
        }
    }
    
    for (const std::pair<char, int> element : letters) {
        if (!(element.second % 2)) {
            length += element.second;
        } else {
            length += (element.second - 1);
            odd = true;
        }
    }
    return length + odd;
}
