#include <string>
#include <assert.h>

/**
 * Problem from LeetCode 392: Is Subsequence. You can find the problem
 * <a href="https://leetcode.com/problems/is-subsequence/">
 * here</a>.
 *
 * @param[in] s: A string
 * @param[in] t: A string
 * @returns A boolean indicating whether s is a subsequence of t
 */
bool is_subsequence(std::string s, std::string t);

int main(int argc, char const *argv[]) {
    std::string test_case_s1 = "abc";
    std::string test_case_t1 = "ahbgdc";
    std::string test_case_s2 = "axc";
    std::string test_case_t2 = "ahbgdc";

    assert(is_subsequence(test_case_s1, test_case_t1));
    assert(!is_subsequence(test_case_s2, test_case_t2));

    return 0;
}

bool is_subsequence(std::string s, std::string t) {
    if (s == t) return true;
    int s_index = 0;
    
    for (std::size_t i = 0; i < t.size(); i++) {
        if (t[i] == s[s_index]) s_index++;
        if (s_index == s.size()) return true;
    }
    
    return false;
}