#include <stack>
#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 503: Next Greater Element II. You can find the
 * problem
 * <a href="https://leetcode.com/problems/next-greater-element-ii/">
 * here</a>.
 *
 * @param[in] nums: A vector of numbers 
 * @returns The Next Greater Number for every element. The Next Greater Number
 * of a number x is the first greater number to its traversing-order next in
 * the array, which means you could search circularly to find its next greater
 * number. If it doesn't exist, output -1 for this number. 
 */
std::vector<int> next_greater_element(std::vector<int> &nums);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1 = {1,2,1};
    std::vector<int> solution = {2,-1,2};

    assert(next_greater_element(test_case_1) == solution);

    return 0;
}

std::vector<int> next_greater_element(std::vector<int> &nums) {
    std::vector<int> output(nums.size(), -1);
    std::stack<int> prev_element;

    for (std::size_t i = 0; i < nums.size(); i++) {
        while (!prev_element.empty() && nums[prev_element.top()] < nums[i]) {
            output[prev_element.top()] = nums[i];
            prev_element.pop();
        }
        prev_element.push(i);
    }
    for (std::size_t i = 0; i < nums.size(); i++) {
        while (!prev_element.empty() && nums[prev_element.top()] < nums[i]) {
            output[prev_element.top()] = nums[i];
            prev_element.pop();
        }
    }

    return output;
}
