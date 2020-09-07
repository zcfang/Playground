#include <vector>
#include <algorithm>
#include <string>
#include <assert.h>

/**
 * Problem from LeetCode 179: Largest Number. You can find the
 * problem <a href="https://leetcode.com/problems/largest-number/">
 * here</a>.
 *
 * @param[in] nums: A list of non negative integers
 * @returns Arrange a list of non negative integers such that they form the
 * largest number.
 */
std::string largest_number(std::vector<int>& nums);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1 = {3,30,34,5,9};
    std::string solution = "9534330";

    assert(largest_number(test_case_1) == solution);

    return 0;
}

std::string largest_number(std::vector<int>& nums) {
    std::string output = "";
    int total = 0;

    total = std::count(nums.begin(), nums.end(), 0);
    if (total == nums.size())
        return "0";
    auto num_sort = [](const int first, const int second) {
        std::string first_str = std::to_string(first) + std::to_string(second);
        std::string sec_str = std::to_string(second) + std::to_string(first);

        for (int i = 0; i < first_str.size(); i++) {
            if (first_str[i] != sec_str[i]) {
                return first_str[i] > sec_str[i];
            }
        }

        return true;
    };
    std::sort(nums.begin(), nums.end(), num_sort);
    for (int val : nums) {
        output += std::to_string(val);
    }

    return output;
}
