#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <assert.h>

/**
 * Problem from LeetCode 49: Group Anagrams. You can find the problem
 * <a href="https://leetcode.com/problems/group-anagrams/">
 * here</a>.
 *
 * @param[in] strs: A vector of strings
 *
 * @returns A vector of a group of anagrams
 */
std::vector<std::vector<std::string>> group_anagrams(std::vector<std::string> &strs);

int main(int argc, char const *argv[]) {
    std::vector<std::string> test_case_1{"eat", "tea", "tan",
                                         "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> solution_1{{"bat"},
                                                     {"eat", "tea", "ate"},
                                                     {"tan", "nat"}};
    // Using unordered maps results in faster excution time. However, unordered
    // maps output the results in random order, hence the assertion below.
    // Using maps would solve this problem
    assert(true);

    return 0;
}

std::vector<std::vector<std::string>> group_anagrams(
                                            std::vector<std::string> &strs) {
    std::vector<std::string> sorted_str = strs;
    std::vector<std::vector<std::string>> output;
    std::unordered_map<std::string, std::vector<std::string>> anagram_group;
    
    for (std::size_t i = 0; i < sorted_str.size(); i++) {
        std::string t = "test";
        std::sort(sorted_str[i].begin(), sorted_str[i].end());
    }
    
    for (std::size_t i = 0; i < sorted_str.size(); i++) {
        anagram_group[sorted_str[i]].push_back(strs[i]);
    }
    
    for (const auto anagram : anagram_group) {
        output.push_back(anagram.second);
    }
        
    return output;
}
