#include <string>
#include <unordered_map>
#include <assert.h>

/**
 * Problem from LeetCode 1347: Minimum Number of Steps to Make Two Strings
 * Anagram. You can find the problem
 * <a href="https://leetcode.com/problems/perform-string-shifts/">
 * here</a>.
 *
 * @param[in] s: A string
 * @param[in] t: A string
 * @returns The minimum number of steps to make `t` an anagram of `s`.
 */
int min_steps(std::string s, std::string t);

int main(int argc, char const *argv[]) {
    std::string s = "bab";
    std::string t = "aba";

    assert(min_steps(s, t) == 1);

    return 0;
}

int min_steps(std::string s, std::string t) {
    std::unordered_map<char, int> s_map;
    std::unordered_map<char, int> t_map;
    int count = 0;

    for (std::size_t i = 0; i < s.size(); i++) {
        s_map[s[i]]++;
        t_map[t[i]]++;
    }

    for (const std::pair<char, int> s_letter : s_map) {
        if (s_letter.second > t_map[s_letter.first]) {
            count += s_letter.second - t_map[s_letter.first];
        }
    }

    return count;
}