#include <vector>
#include <map>
#include <assert.h>

/**
 * Problem from LeetCode 350: Intersection of Two Arrays II. You can find the
 * problem
 * <a href="https://leetcode.com/problems/intersection-of-two-arrays-ii/">
 * here</a>.
 *
 * @param[in] nums1: A vector of numbers
 * @param[in] nums2: A vector of numbers
 * @returns A vector where the values are the intersection of nums1 and nums2
 */
std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2);

int main(int argc, char const *argv[]) {
    std::vector<int> nums1{1,2,2,1};
    std::vector<int> nums2{2,2};


    std::vector<int> output = intersect(nums1, nums2);

    return 0;
}

std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::vector<int> output;
    std::map<int, int> numbers;

    for (int value : nums1) {
        if (numbers.count(value)) numbers[value] += 1;
        else numbers[value] = 1;
    }

    for (int value : nums2) {
        if (numbers.count(value)) {
            if (numbers[value] > 0) {
                output.push_back(value);
                numbers[value] -= 1;
            }
        }
    }

    return output;
}
