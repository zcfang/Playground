#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 34: Find First and Last Position of Element in Sorted
 * Array. You can find the problem
 * <a href="https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/">
 * here</a>.
 *
 * @param[in] nums: An array of integers sorted in ascending order
 * @param[in] target: Target value
 * @returns The starting and ending position of a given `target` value. If the
 * `target` is not found in the array, return [-1, -1].
 */
std::vector<int> search_range(std::vector<int> &nums, int target);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1 = {5,7,7,8,8,10};
    int target = 8;
    std::vector<int> solution = {3,4};

    assert(search_range(test_case_1, target) == solution);

    return 0;
}

std::vector<int> search_range(std::vector<int> &nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    std::vector<int> output = {-1,-1};

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] > target) {
            end = mid - 1;
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else {
            output[0] = (output[0] == -1) ? mid : std::min(output[0], mid);
            end = mid - 1;
        }
    }

    start = 0;
    end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] > target) {
            end = mid - 1;
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else {
            output[1] = (output[1] == -1) ? mid : std::max(output[0], mid);
            start = mid + 1;
        }
    }

    return output;
}
