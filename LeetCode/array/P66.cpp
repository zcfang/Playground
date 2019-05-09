#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 66: Plus One. You can find the problem
 * <a href="https://leetcode.com/problems/plus-one/">
 * here</a>.
 *
 * @param[in] digits: A vector of digits where the most significant digit is
 * index 0
 * @returns A vector of digits representing the input plus one
 */
std::vector<int> plus_one(std::vector<int> &digits);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{1,2,3};
    std::vector<int> test_case_2{4,3,2,1};

    plus_one(test_case_1);
    plus_one(test_case_2);

    return 0;
}

std::vector<int> plus_one(std::vector<int> &digits) {
    for (std::size_t i = digits.size(); i > 0; i--) {
        if (digits[i - 1] == 9) digits[i - 1] = 0;
        else {
            digits[i - 1] += 1;
            break;
        }
    }
    if (!digits[0]) {
        digits[0] = 1;
        digits.push_back(0);
    }

    return digits;
}