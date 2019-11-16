#include <string>
#include <map>
#include <set>
#include <assert.h>

/**
 * Problem from LeetCode 205: Isomorphic Strings. You can find the problem
 * <a href="https://leetcode.com/problems/isomorphic-strings/">
 * here</a>.
 *
 * @param[in] s: A string
 * @param[in] t: A string
 * @returns A boolean indicating whether s and t are isomorphic
 */
bool is_isomorphic(std::string s, std::string t);

int main(int argc, char const *argv[]) {
    std::string test_case_1_s1 = "egg";
    std::string test_case_1_s2 = "add";

    assert(is_isomorphic(test_case_1_s1, test_case_1_s2));

    return 0;
}

bool is_isomorphic(std::string s, std::string t) {
    std::map<char, char> letter_map;
    std::set<char> mapped_char;

    for (std::size_t i = 0; i < s.size(); i++) {
        if (letter_map.count(s[i])) {
            s[i] = letter_map[s[i]];
        } else if (!mapped_char.count(t[i])) {
            letter_map[s[i]] = t[i];
            mapped_char.insert(t[i]);
            s[i] = t[i];
        }
    }

    return (s == t);
}
