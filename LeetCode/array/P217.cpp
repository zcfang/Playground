#include <unordered_set>
#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 217: Contains Duplicate. You can find the
 * problem
 * <a href="https://leetcode.com/problems/contains-duplicate/">
 * here</a>.
 *
 * @param[in] nums: A vector of number
 * @returns A boolean indicating if there are duplicate values
 */
bool contains_duplicate(std::vector<int> &nums);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{1,2,3,1};
    std::vector<int> test_case_2{1,2,3,4};
    std::vector<int> test_case_3{1,1,1,3,3,4,3,2,4,2};

    assert(contains_duplicate(test_case_1));
    assert(!contains_duplicate(test_case_2));
    assert(contains_duplicate(test_case_3));

    return 0;
}

bool contains_duplicate(std::vector<int> &nums) {
    std::unordered_set<int> unique_value;
    std::unordered_set<int>::const_iterator in_set; 

    for (int element : nums) {
        in_set = unique_value.find(element);
        if (in_set == unique_value.end()) {
            unique_value.insert(element);
        } else return true;
    }
    return false;
}