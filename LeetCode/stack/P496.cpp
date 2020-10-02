#include <stack>
#include <vector>
#include <unordered_map>
#include <assert.h>

/**
 * Problem from LeetCode 496: Next Greater Element I. You can find the
 * problem
 * <a href="https://leetcode.com/problems/next-greater-element-i/">
 * here</a>.
 *
 * @param[in] nums1: A subset of `nums2` 
 * @param[in] nums2: A vector of numbers 
 * @returns The next greater numbers for `nums1`'s elements in the
 * corresponding places of `nums2`. The Next Greater Number of a number x in
 * `nums1` is the first greater number to its right in `nums2`. If it does not
 * exist, output -1 for this number.  
 */
std::vector<int> next_greater_element(std::vector<int> &nums1,
                                      std::vector<int> &nums2);

int main(int argc, char const *argv[]) {
    std::vector<int> nums1 = {4,1,2};
    std::vector<int> nums2 = {1,3,4,2};
    std::vector<int> solution = {-1,3,-1};

    assert(next_greater_element(nums1, nums2) == solution);

    return 0;
}

std::vector<int> next_greater_element(std::vector<int> &nums1,
                                      std::vector<int> &nums2) {
    std::vector<int> output;
    std::unordered_map<int, int> next_element;
    std::stack<int> prev_element;

    for (std::size_t i = 0; i < nums2.size(); i++) {
        while (!prev_element.empty() && prev_element.top() < nums2[i]) {
            next_element[prev_element.top()] = nums2[i];
            prev_element.pop();
        }
        prev_element.push(nums2[i]);
    }
    for (const int val : nums1) {
        int next = next_element.count(val) ? next_element[val] : -1;
        output.push_back(next);
    }

    return output;
}
