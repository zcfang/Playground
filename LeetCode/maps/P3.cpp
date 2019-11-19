#include <string>
#include <map>
#include <assert.h>

/**
 * Problem from LeetCode 3: Longest Substring Without Repeating Characters.
 * You can find the problem
 * <a href="https://leetcode.com/problems/longest-substring-without-repeating-characters/">
 * here</a>.
 *
 * @param[in] s: A string
 * @returns Length of longest substring without repeating characters
 */
int length_of_longest_substring(std::string s);

int main(int argc, char const *argv[]) {
    std::string test_case_1 = "abcabcbb";
    std::string test_case_2 = "bbbbb";
    std::string test_case_3 = "pwwkew";

    assert(length_of_longest_substring(test_case_1) == 3);
    assert(length_of_longest_substring(test_case_2) == 1);
    assert(length_of_longest_substring(test_case_3) == 3);

    return 0;
}

int length_of_longest_substring(std::string s) {
    std::map<char, int> char_map;
    int max_length = 0;
    int start = 0;
    
    for (std::size_t i = 0; i < s.size(); i++) {
        if (char_map.count(s[i])) {
            max_length = (i - start) > max_length ? (i - start) : max_length;
            start = start > char_map[s[i]] ? start : char_map[s[i]] + 1;
            char_map[s[i]] = i;
        } else {
            char_map[s[i]] = i;
        }
    }
    if (!start) {
        max_length = s.size();
    } else {
        if (s.size() - start > max_length) max_length = s.size() - start;
    }
    return max_length;
}
