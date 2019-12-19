#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 75: Sort Colors. You can find the
 * problem <a href="https://leetcode.com/problems/sort-colors/">
 * here</a>.
 *
 * @param[in,out] nums: A vector of numbers of the set (0, 1, 2). Returns the
 * vector sorted
 */
void sort_colors(std::vector<int> &nums);

int main(int argc, char const *argv[]) {
    std::vector<int> nums{2,0,2,1,1,0};
    std::vector<int> solution{0,0,1,1,2,2};

    sort_colors(nums);
    assert(nums == solution);

    return 0;
}

void sort_colors(std::vector<int> &nums) {
    int i = 0;
    int j = nums.size() - 1;
    int k = 0;

    while (k <= j) {
        if (nums[k] == 0 && nums[i] != 0) {
            std::swap(nums[i], nums[k]);
            i++;
        } else if (nums[k] == 2 && nums[j] != 2) {
            std::swap(nums[j], nums[k]);
            j--;
        }
        if (nums[i] == 0) i++;
        if (nums[j] == 2) j--;
        if (nums[k] == 1 || k < i) k++;
    }
}
