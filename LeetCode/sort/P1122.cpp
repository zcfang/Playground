#include <vector>
#include <map>
#include <assert.h>

/**
 * Problem from LeetCode 1122: Relative Sort Array. You can find the
 * problem <a href="https://leetcode.com/problems/relative-sort-array/">
 * here</a>.
 *
 * @param[in] arr1: A vector of numbers
 * @param[in] arr2: A vector of unique numbers
 * @returns A vector such that the elements of arr1 is sorted relative to arr2.
 * Elements that don't appear in arr2 should be placed at the end of arr1 in
 * ascending order.
 */
std::vector<int> relative_sort_array(std::vector<int>& arr1,
                                     std::vector<int>& arr2);

int main(int argc, char const *argv[]) {
    std::vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    std::vector<int> arr2 = {2,1,4,3,9,6};
    std::vector<int> solution = {2,2,2,1,4,3,3,9,6,7,19};

    assert(relative_sort_array(arr1, arr2) == solution);

    return 0;
}

std::vector<int> relative_sort_array(std::vector<int>& arr1,
                                     std::vector<int>& arr2) {
    int i = 0;
    std::map<int, int> count;

    for (const int value : arr1) {
        count[value]++;
    }
    for (const int unique_val : arr2) {
        int iter = count[unique_val];
        for (int j = 0; j < iter; j++) {
            arr1[i] = unique_val;
            i++;
        }
        count.erase(unique_val);
    }
    for (const std::pair<int, int> map_val : count) {
        for (int j = 0; j < map_val.second; j++) {
            arr1[i] = map_val.first;
            i++;
        }
    }
    
    return arr1;
}
