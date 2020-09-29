#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 713: Subarray Product Less Than K. You can find the
 * problem
 * <a href="https://leetcode.com/problems/subarray-product-less-than-k/">
 * here</a>.
 *
 * @param[in] nums: A vector of numbers
 * @param[in] k: A number
 * @returns The number of (contiguous) subarrays where the product of all the
 * elements in the subarray is less than `k`.
 */
int num_subarray_product_less_than_k(std::vector<int> &nums, int k);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1 = {10, 5, 2, 6};
    int k = 100;
    int solution = 8;

    assert(num_subarray_product_less_than_k(test_case_1, k) == solution);

    return 0;
}

int num_subarray_product_less_than_k(std::vector<int> &nums, int k) {
    int count = 0;
    int product = 1;
    int last_element = -1;

    for (int i = 0; i < nums.size(); i++) {
        product *= nums[i];
        while (product >= k && last_element < i) {
            product /= nums[++last_element];
        }
        count += (i - last_element);
    }

    return count;
}
