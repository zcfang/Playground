#include <vector>
#include <cmath>
#include <assert.h>

/**
 * Problem from LeetCode 414: Third Maximum Number. You can find the problem
 * <a href="https://leetcode.com/problems/third-maximum-number/">
 * here</a>.
 *
 * @param[in] nums: A vector of numbers
 * @returns The third maximum number in this array. If it does not exist,
 * return the maximum number. The time complexity must be in O(n).
 */
int third_max(std::vector<int> &nums);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{1,2,3};
    std::vector<int> test_case_2{1,2};

    assert(third_max(test_case_1) == 1);
    assert(third_max(test_case_2) == 2);

    return 0;
}

int third_max(std::vector<int> &nums) {
    double first = -INFINITY;
    double second = -INFINITY;
    double third = -INFINITY;
    int output;
    
    for (const int value : nums) {
        if (first < value) {
            third = second;
            second = first;
            first = value;
        } else if (second < value && value != first) {
            third = second;
            second = value;
        } else if (third < value && value != first && value != second) {
            third = value;
        }
    }
    output = third != -INFINITY ? third : first;

    return output;
}