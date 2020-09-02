#include <vector>
#include <algorithm>
#include <assert.h>

/**
 * Problem from LeetCode 1094: Car Pooling. You can find the
 * problem <a href="https://leetcode.com/problems/car-pooling/">
 * here</a>.
 *
 * @param[in] intervals: Collection of intervals
 * @returns The number of remaining intervals after removing covered intervals
 */
int remove_covered_intervals(std::vector<std::vector<int>> &intervals);

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> test_case_1 = {{1,4},{3,6},{2,8}};
    int solution = 2;

    assert(remove_covered_intervals(test_case_1) == solution);

    return 0;
}

int remove_covered_intervals(std::vector<std::vector<int>> &intervals) {
    int count = 0;
    int prev_end = 0;

    std::sort(intervals.begin(), intervals.end(),
              [](std::vector<int> &first, std::vector<int> &second) {
                  if (first[0] == second[0]) 
                      return first[1] > second[1];
                  return first[0] < second[0];
              });
    for (const std::vector<int> interval : intervals) {
        if (interval[1] > prev_end) {
            count++;
            prev_end = interval[1];
        }
    }

    return count;
}
