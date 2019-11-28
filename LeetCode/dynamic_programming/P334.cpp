#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 334: Increasing Triplet Subsequence. You can find the
 * problem
 * <a href="https://leetcode.com/problems/increasing-triplet-subsequence/">
 * here</a>.
 *
 * @param[in] nums: A vector of numbers
 * @returns Whether an increasing subsequence of length 3 exists or not in the
 * vector
 */
bool increasing_triplet(std::vector<int> &nums);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{1,2,3,4,5};
    std::vector<int> test_case_2{5,4,3,2,1};

    assert(increasing_triplet(test_case_1));
    assert(!increasing_triplet(test_case_2));

    return 0;
}

bool increasing_triplet(std::vector<int> &nums) {
    int first = INT_MAX;
    int second = INT_MAX;
    
    for (std::size_t i = 0; i < nums.size(); i++) {
        if (first > nums[i]) {
            first = nums[i];
        } else if (second > nums[i] && first != nums[i]) {
            second = nums[i];
        } else if (first != nums[i] && second != nums[i]) {
            return true;
        }
    }

    return false;
}
