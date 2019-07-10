#include <vector>
#include <map>
#include <assert.h>

/**
 * Problem from LeetCode 1: Two Sum. You can find the problem
 * <a href="https://leetcode.com/problems/two-sum/">
 * here</a>.
 *
 * @param[in] prices: A vector of numbers
 * @returns A vector with two indexes where the corresponding value sums to the
 * target 
 */
std::vector<int> two_sum(std::vector<int> &nums, int target);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{2,7,11,15};
    int target_1 = 9;

    std::vector<int> output = two_sum(test_case_1, target_1);

    return 0;
}

std::vector<int> two_sum(std::vector<int> &nums, int target) {
    std::vector<int> output;
    std::map<int, int> target_diff;
    for (std::size_t i = 0; i < nums.size(); i++) {;
        if (!target_diff.count(nums[i])) {
            target_diff[target - nums[i]] = i;
        } else {
            output.push_back(target_diff[nums[i]]);
            output.push_back(i);
        }
    }

    return output;
}
