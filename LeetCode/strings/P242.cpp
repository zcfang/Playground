#include <string>
#include <map>
#include <assert.h>

/**
 * Problem from LeetCode 242: Valid Anagram. You can find the problem
 * <a href="https://leetcode.com/problems/valid-anagram/">
 * here</a>.
 *
 * @param[in] s: A string
 * @param[in] t: A string
 * @returns A boolean indicating whether string `t` is an anagram of string `s`
 */
bool is_anagram(std::string s, std::string t);

int main(int argc, char const *argv[]) {
    std::string test_case_s1 = "anagram";
    std::string test_case_t1 = "nagaram";
    std::string test_case_s2 = "rat";
    std::string test_case_t2 = "car";

    assert(is_anagram(test_case_s1, test_case_t1));
    assert(!is_anagram(test_case_s2, test_case_t2));

    return 0;
}

bool is_anagram(std::string s, std::string t) {
    std::map<char, std::size_t> char_map;

    if (s.size() != t.size()) return false;
    for (char value : s) {
        if (char_map.count(value)) char_map[value] += 1;
        else char_map.insert(std::pair<char, std::size_t>(value, 1));
    }

    for (char value : t) {
        if (char_map.count(value)) {
            if (char_map[value] == 0) return false;
            else char_map[value] -= 1;
        } else return false;
    }

    return true;
}