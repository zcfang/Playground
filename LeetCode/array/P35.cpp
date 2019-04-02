#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 35: Search Insert Position. You can find the
 * problem
 * <a href="https://leetcode.com/problems/search-insert-position/">
 * here</a>.
 *
 * @param[in] nums: A vector of number
 * @param[in] target: Value to insert into vector nums
 * @returns Position to insert target value if target value is not found in
 * vector. If target value is found, the index of the target value is returned.
 */
int search_insert(std::vector<int> &nums, int target);

int main(int argc, char const *argv[]) {
    std::vector<int> test_vector{1,3,5,6};

    assert(search_insert(test_vector, 5) == 2);
    assert(search_insert(test_vector, 2) == 1);
    assert(search_insert(test_vector, 7) == 4);
    assert(search_insert(test_vector, 0) == 0);
    return 0;
}

int search_insert(std::vector<int> &nums, int target) {
    for (std::size_t i = 0; i < nums.size(); i++) {
        if ((nums[i] == target) || (target < nums[i])) return i;
    }
    return nums.size();
}