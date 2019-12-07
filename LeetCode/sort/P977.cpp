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
    std::vector<int> output;
    int i = -1;
    
    for (std::size_t j = 0; j < A.size(); j++) {
        if (A[j] >= 0) {
            i = j;
            break;
        }
    }
    if (i == 0) {
        output = A;
    } else if (i == - 1) {
        std::reverse(A.begin(), A.end());
        output = A;
    } else {
        int j = i - 1;
        while (j >= 0 || i != A.size()) {
            if (j < 0) {
                output.push_back(A[i]);
                i++;
            } else if (i == A.size()) {
                output.push_back(A[j]);
                j--;
            } else if (A[i] > A[j] * -1) {
                output.push_back(A[j]);
                j--;
            } else {
                output.push_back(A[i]);
                i++;
            }
        }
    }

    for (std::size_t k = 0; k < output.size(); k++) {
        output[k] *= output[k];
    }

    return output;
}
