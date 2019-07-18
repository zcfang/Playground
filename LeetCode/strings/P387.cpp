#include <string>
#include <map>
#include <assert.h>

/**
 * Problem from LeetCode 387: First Unique Character in a String. You can find
 * the problem
 * <a href="https://leetcode.com/problems/first-unique-character-in-a-string/">
 * here</a>.
 *
 * @param[in] s: A string
 * @returns An index corresponding to the first unique character in a string
 */
int first_uniq_char(std::string s);

int main(int argc, char const *argv[]) {
    std::string test_case_1 = "leetcode";
    std::string test_case_2 = "loveleetcode";

    assert(first_uniq_char(test_case_1) == 0);
    assert(first_uniq_char(test_case_2) == 2);
    return 0;
}

int first_uniq_char(std::string s) {
    std::map<char, int> char_map;
    std::size_t n = s.size();

    for (char c : s) {
        if (char_map.count(c)) char_map[c] += 1;
        else char_map[c] = 1;
    }

    for (std::size_t i = 0; i < n; i++) {
        if (char_map[s[i]] == 1) return i;
    }
    return -1;
}