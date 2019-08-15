#include <vector>
#include <assert.h>

class NumArray {
public:
    std::vector<int> running_sum;
    /**
     * Problem from LeetCode 303: Range Sum Query - Immutable. You can find the
     * problem
     * <a href="https://leetcode.com/problems/range-sum-query-immutable/">
     * here</a>.
     *
     * @param[in] s: A vector of numbers
     */
    NumArray(std::vector<int> &nums) {
        running_sum.resize(nums.size());
        if (nums.size()) {
            running_sum[0] = nums[0];
        
            for (std::size_t i = 1; i < nums.size(); i++) {
                running_sum[i] = nums[i] + running_sum[i - 1];
            }
        }
    }
    
    /**
     * Sum value from index i to j inclusively
     *
     * @param[in] i: Starting index to sum value
     * @param[in] j: End index
     * @returns Returns the sum from index i to j inclusively
     */
    int sum_range(int i, int j) {
        if (i == 0) return running_sum[j];
        else return (running_sum[j] - running_sum[i - 1]);
    }
};

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1 = {-2,0,3,-5,2,-1};
    NumArray num_array(test_case_1);

    assert(num_array.sum_range(0, 2) == 1);
    assert(num_array.sum_range(2, 5) == -1);
    assert(num_array.sum_range(0, 5) == -3);
    return 0;
}
