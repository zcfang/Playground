#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 338: Counting Bits. You can find the problem
 * <a href="https://leetcode.com/problems/counting-bits/">
 * here</a>.
 *
 * @param[in] nums: For every numbers i in the range 0 ≤ i ≤ num calculate the
 * number of 1's in their binary representation and return them as an array.
 * @returns An array indicating the number of one bits for the corresponding
 * index
 */
std::vector<int> count_bits(int num);

int main(int argc, char const *argv[]) {
    int test_case_1 = 2;
    int test_case_2 = 5;
    std::vector<int> test_case_1_solution{0,1,1};
    std::vector<int> test_case_2_solution{0,1,1,2,1,2};

    assert(count_bits(test_case_1) == test_case_1_solution);
    assert(count_bits(test_case_2) == test_case_2_solution);

    return 0;
}

std::vector<int> count_bits(int num) {
    std::vector<int> result(num + 1, 0);
    for (std::size_t i = 1; i <= num; i++) {
        result[i] = result[(i - 1) & i] + 1;
    }
    
    return result;
}