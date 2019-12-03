#include <vector>
#include <iostream>
#include <assert.h>

/**
 * Problem from LeetCode 912: Sort an Array =. You can find the
 * problem <a href="https://leetcode.com/problems/sort-an-array/">
 * here</a>.
 *
 * @param[in] nums: A vector of numbers;
 * @returns A sorted version of nums
 */
std::vector<int> sort_array(std::vector<int> &nums);

/**
 * Partition an array into two halves where values greater than the selected
 * pivot will move to the right and values less than the pivot will move to the
 * left.
 *
 * @param[in,out] array: An array where values greater than the selected
 * pivot will move to the right and values less than the pivot will move to the
 * left.
 * @param[in] start: Starting index to execute function
 * @param[in] end: Ending index to execute function
 * @returns Index of pivot
 */
int partition(std::vector<int> &array, int start, int end) {
    int pivot = array[end];
    int i = start;

    for (std::size_t j = start; j < end; j++) {
        if (array[j] <= pivot) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
        }
    }
    array[end] = array[i];
    array[i] = pivot;

    return i;
}

/**
 * Quicksort algorithm to sort array
 *
 * @param[in,out] array: Input array is sorted in place
 * @param[in] start: Starting index to execute function
 * @param[in] end: Ending index to execute function
 */
void quicksort(std::vector<int> &array, int start, int end) {
    if (start < end) {
        int q = partition(array, start, end);
        quicksort(array, start, q - 1);
        quicksort(array, q + 1, end);
    }
}


int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{2,8,7,1,3,5,6,4};
    std::vector<int> solution_1{1,2,3,4,5,6,7,8};

    assert(sort_array(test_case_1) == solution_1);
}

std::vector<int> sort_array(std::vector<int> &nums) {
    quicksort(nums, 0, nums.size() - 1);

    return nums;
}
