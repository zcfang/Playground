#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 136: Single Number. You can find the
 * problem
 * <a href="https://leetcode.com/problems/single-number/">
 * here</a>.
 *
 * @param[in] prices: A vector of numbers
 * @returns An int representing a single non repeating number in the vector
 */
int single_number(std::vector<int> &nums);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{2,2,1};
    std::vector<int> test_case_2{4,1,2,1,2};

    assert(single_number(test_case_1) == 1);
    assert(single_number(test_case_2) == 4);

    return 0;
}

int single_number(std::vector<int> &nums) {
    int single_number = 0;

    for (int value : nums) {
        single_number ^= value;
    }

    return single_number;
}
