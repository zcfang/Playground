#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 1051: Height Checker. You can find the
 * problem <a href="https://leetcode.com/problems/height-checker/">
 * here</a>.
 *
 * @param[in] heights: A vector of heights;
 * @returns The minimum number of students not standing in the right positions.
 * (This is the number of students that must move in order for all students to
 * be standing in non-decreasing order of height.)
 */
int height_checker(std::vector<int> &heights);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{1,1,4,2,1,3};

    assert(height_checker(test_case_1) == 3);

    return 0;
}

int height_checker(std::vector<int> &heights) {
    std::vector<int> count(101, 0);
    int output = 0;
    
    for (const int height : heights) {
        count[height]++;
    }
    
    for (std::size_t i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    for (const int height : heights) {
        if (heights[count[height] - 1] != height) output++;
        count[height]--;
    }

    return output;
}
