#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 88: Merge Sorted Array. You can find the
 * problem <a href="https://leetcode.com/problems/merge-sorted-array/">
 * here</a>.
 *
 * @param[in,out] nums1: A vector of sorted values. This vector will be
 * modified where nums1 and nums2 is merged as one sorted array.
 * @param[in] m: Length of nums1.
 * @param[in] nums2: A vector of sorted values.
 * @param[in] n: Length of nums2.
 */
void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n);

int main(int argc, char const *argv[]) {
    std::vector<int> nums1{1,2,3,0,0,0};
    std::vector<int> nums2{2,5,6};
    std::vector<int> solution{1,2,2,3,5,6};
    int m = 3;
    int n = 3;

    merge(nums1, m, nums2, n);
    assert(nums1 == solution);

    return 0;
}

void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int i = 0;
    int j = 0;
    std::vector<int> output;
    
    while ((i != m) || (j != n)) {
        if (i == m) {
            output.push_back(nums2[j]);
            j++;
        } else if (j == n) {
            output.push_back(nums1[i]);
            i++;
        } else if (nums1[i] < nums2[j]) {
            output.push_back(nums1[i]);
            i++;
        } else {
            output.push_back(nums2[j]);
            j++;
        }
    }
    nums1 = output;
}
