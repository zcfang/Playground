#include <vector>
#include <algorithm>
#include <assert.h>

/**
 * Problem from LeetCode 977: Squares of a Sorted Array. You can find the
 * problem <a href="https://leetcode.com/problems/squares-of-a-sorted-array/">
 * here</a>.
 *
 * @param[in] heights: A vector of numbers
 * @returns An array of the squares of each number sorted in non-decreasing
 * order.
 */
std::vector<int> sorted_squares(std::vector<int> &A);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{-4,-1,0,3,10};
    std::vector<int> solution_1{0,1,9,16,100};

    assert(sorted_squares(test_case_1) == solution_1);

    return 0;
}

std::vector<int> sorted_squares(std::vector<int> &A) {
    std::vector<int> output = A;
    
    for (std::size_t i = 0; i < output.size(); i++) {
        output[i] *= output[i];
    }
    sort(output.begin(), output.end());
    
    return output;
}
