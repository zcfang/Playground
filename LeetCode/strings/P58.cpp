#include <string>
#include <assert.h>

/**
 * Problem from LeetCode 58: Length of Last Word. You can find the
 * problem <a href="https://leetcode.com/problems/length-of-last-word/">
 * here</a>.
 *
 * @param[in] s: A string
 * @returns Given a string, return the length of last word
 */
int length_of_last_word(std::string s);

int main(int argc, char const *argv[]) {
    std::string test_case_1 = "Hello World";
    std::string test_case_2 = "a      b     ";
    int solution_1 = 5;
    int solution_2 = 1;

    assert(length_of_last_word(test_case_1) == solution_1);
    assert(length_of_last_word(test_case_2) == solution_2);

    return 0;
}

int length_of_last_word(std::string s) {
    int count = 0;
    bool end = false;
    bool start = false;

    while (!end && s.size()) {
        if (!start && std::isalpha(s.back())) {
            start = true;
            count++;
            s.pop_back();
        } else if (start && std::isalpha(s.back())) {
            count++;
            s.pop_back();
        } else if (!start && !std::isalpha(s.back())) {
            s.pop_back();
        } else if (start && !std::isalpha(s.back())) {
            end = true;
        }
    }

    return count;
}
