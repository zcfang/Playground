#include <unordered_map>
#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 219: Contains Duplicate II. You can find the
 * problem
 * <a href="https://leetcode.com/problems/contains-duplicate-ii/">
 * here</a>.
 *
 * @param[in] nums: A vector of numbers
 * @param[in] k: Absolute difference between i and j where nums[i] == nums[j] 
 * @returns A boolean indicating if there are duplicate values within k
 * distances apart
 */
bool contains_nearby_duplicate(std::vector<int> &nums, int k);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{1,2,3,1};
    std::vector<int> test_case_2{1,0,1,1};
    std::vector<int> test_case_3{1,2,3,1,2,3};
    int k1 = 3;
    int k2 = 1;
    int k3 = 2;

    assert(contains_nearby_duplicate(test_case_1, k1));
    assert(contains_nearby_duplicate(test_case_2, k2));
    assert(!contains_nearby_duplicate(test_case_3, k3));

    return 0;
}

bool contains_nearby_duplicate(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> x;
        
    for (std::size_t i = 0; i < nums.size(); i++) {
        if (!x.count(nums[i])) x[nums[i]] = i;
        else if (i - x[nums[i]] > k) x[nums[i]] = i;
        else return true;
    }
    return false;
}
