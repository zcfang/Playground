#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 704: Binary Search. You can find the problem
 * <a href="https://leetcode.com/problems/binary-search/">
 * here</a>.
 *
 * @param[in] nums: A vector of numbers
 * @param[in] target: Find target value in `nums`
 * @returns  If `target` exists in `nums`, return its index, otherwise return
 * -1.
 */
int search(std::vector<int> &nums, int target);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1 = {-1,0,3,5,9,12};
    int target = 9;
    int solution = 4;

    assert(search(test_case_1, target) == solution);

    return 0;
}

int search(std::vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
