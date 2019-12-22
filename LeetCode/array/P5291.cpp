#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 5291: Find Numbers with Even Number of Digits. You can
 * find the problem
 * <a href="https://leetcode.com/problems/find-numbers-with-even-number-of-digits/">
 * here</a>.
 *
 * @param[in] nums: A vector of numbers
 * @returns How many values in nums contain an even number of digits
 */
int find_numbers(std::vector<int> &nums);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1 = {12,345,2,6,7896};

    assert(find_numbers(test_case_1) == 2);

    return 0;
}

int find_numbers(std::vector<int> &nums) {
    int output = 0;

    for (int value : nums) {
        int count = 0;
        while (value) {
            value /= 10;
            count++;
        }
        if (!(count % 2)) output++;
    }
    
    return output;
}
