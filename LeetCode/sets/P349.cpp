#include <vector>
#include <set>
#include <assert.h>

/**
 * Problem from LeetCode 349: Intersection of Two Arrays. You can find the
 * problem <a href="https://leetcode.com/problems/intersection-of-two-arrays/">
 * here</a>.
 *
 * @param[in] nums1: A vector of numbers
 * @param[in] nums2: A vector of numbers
 * @returns A standard vector with unique common values of nums1 and nums2
 */
std::vector<int> intersection(std::vector<int> &nums1,
                              std::vector<int> &nums2);

int main(int argc, char const *argv[]) {
    std::vector<int> nums1{1,2,2,1};
    std::vector<int> nums2{2,2};
    std::vector<int> solution_1{2};
    std::vector<int> output;

    assert(intersection(nums1, nums2) == solution_1);

    return 0;
}

std::vector<int> intersection(std::vector<int> &nums1,
                              std::vector<int> &nums2) {
    std::set<int> set_1;
    std::set<int> set_2;
    std::vector<int> output;
    for (const int value : nums1) {
        set_1.insert(value);
    }
    for (const int value : nums2) {
        set_2.insert(value);
    }
    for (const int value : set_1) {
        if (set_2.count(value)) {
            output.push_back(value);
        }
    }

    return output;
}
