#include <string>
#include <set>
#include <assert.h>

/**
 * Problem from LeetCode 771: Jewels and Stones. You can find the
 * problem <a href="https://leetcode.com/problems/jewels-and-stones/">
 * here</a>.
 *
 * @param[in] J: A string where each unique character represents a jewel
 * @param[in] S: A string where each character represents a stone
 * @returns The number of stones that is a jewel
 */
int num_jewels_in_stones(std::string J, std::string S);

int main(int argc, char const *argv[]) {
    std::string J = "aA";
    std::string S = "aAAbbbb";

    assert(num_jewels_in_stones(J, S) == 3);

    return 0;
}

int num_jewels_in_stones(std::string J, std::string S) {
    std::set<char> jewels;
    int total = 0;

    for (const char jewel : J) {
        jewels.insert(jewel);
    }
    
    for (const char stone : S) {
        if (jewels.count(stone)) {
            total++;
        }
    }

    return total;
}
