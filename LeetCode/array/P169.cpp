#include <unordered_map>
#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 169: Majority Element. You can find the
 * problem
 * <a href="https://leetcode.com/problems/majority-element/">
 * here</a>.
 *
 * @param[in] nums: A vector of numbers
 * @returns The majority element in `nums`.
 */
int majority_element(std::vector<int> &nums);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{3,2,3};
    std::vector<int> test_case_2{2,2,1,1,1,2,2};

    assert(majority_element(test_case_1) == 3);
    assert(majority_element(test_case_2) == 2);

    return 0;
}

int majority_element(std::vector<int> &nums) {
    std::unordered_map<int, int> element_count;
        
    for (int value : nums) {
        if (!element_count.count(value)) element_count[value] = 1;
        else element_count[value] += 1;
        if (element_count[value] > nums.size() / 2) return value;
    }

    return 0;
}
