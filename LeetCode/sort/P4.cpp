#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 4: Median of Two Sorted Array. You can find the
 * problem
 * <a href="https://leetcode.com/problems/median-of-two-sorted-arrays/">
 * here</a>.
 *
 * @param[in] nums1: A vector of sorted values.
 * @param[in] nums2: A vector of sorted values.
 * @returns The median of the two sorted arrays
 */
double find_median_sorted_arrays(std::vector<int> &nums1,
                                 std::vector<int> &nums2);

int main(int argc, char const *argv[]) {
    std::vector<int> nums1{1,2};
    std::vector<int> nums2{3,4};

    assert(find_median_sorted_arrays(nums1, nums2) == 2.5);

    return 0;
}

double find_median_sorted_arrays(std::vector<int> &nums1,
                                 std::vector<int> &nums2) {
    int i = 0;
    int j = 0;
    int m = nums1.size();
    int n = nums2.size();
    double median;
    std::vector<int> merged;
    
    while ((i != m) || (j != n)) {
        if (i == m) {
            merged.push_back(nums2[j]);
            j++;
        } else if (j == n) {
            merged.push_back(nums1[i]);
            i++;
        } else if (nums1[i] < nums2[j]) {
            merged.push_back(nums1[i]);
            i++;
        } else {
            merged.push_back(nums2[j]);
            j++;
        }
    }
    
    if ((m + n) % 2) {
        median = merged[(m + n) / 2];            
    } else {
        median = (double) (merged[(m + n) / 2] +
                           merged[(m + n) / 2 - 1]) / 2;
    }

    return median;
}
