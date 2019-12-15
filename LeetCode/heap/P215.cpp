#include <vector>
#include <algorithm>
#include <functional>
#include <assert.h>

/**
 * Problem from LeetCode 215: Kth Largest Element in an Array. You can find the
 * problem
 * <a href="https://leetcode.com/problems/kth-largest-element-in-an-array/">
 * here</a>.
 *
 * @param[in] nums: A vector of unsorted numbers
 * @param[in] k: kth largest number
 * @returns The kth largest element in an unsorted array. Note that it is the
 * kth largest element in the sorted order, not the kth distinct element.
 */
int find_kth_largest(std::vector<int> &nums, int k);

int main(int argc, char const *argv[]) {
    std::vector<int> nums{3,2,1,5,6,4};
    int k = 2;

    assert(find_kth_largest(nums, k) == 5);

    return 0;
}

int find_kth_largest(std::vector<int> &nums, int k) {
    std::make_heap(nums.begin(), nums.end());

    for (int i = 0; i < k - 1; i++) {
        std::pop_heap(nums.begin(), nums.end());
        nums.pop_back();
    }

    return nums[0];
}
