#include <vector>
#include <algorithm>
#include <assert.h>

/**
 * Problem from LeetCode 435: Non-overlapping Intervals. You can find the
 * problem <a href="https://leetcode.com/problems/non-overlapping-intervals/">
 * here</a>.
 *
 * @param[in] intervals: Collection of intervals
 * @returns The minimum number of intervals you need to remove to make the
 * rest of the intervals non-overlapping.
 */
int erase_overlap_intervals(std::vector<std::vector<int>> &intervals);

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> test_case_1 = {{1,2},
                                                 {2,3},
                                                 {3,4},
                                                 {1,3}};
    int solution = 1;

    assert(erase_overlap_intervals(test_case_1) == solution);

    return 0;
}

int erase_overlap_intervals(std::vector<std::vector<int>> &intervals) {
    std::vector<std::vector<int>> no_overlap;

    std::sort(intervals.begin(), intervals.end());
    if (intervals.size()) {
        no_overlap.push_back(intervals.front());
    }
    for (std::size_t i = 1; i < intervals.size(); i++) {
        if (no_overlap.back()[1] <= intervals[i][0]) {
            no_overlap.push_back(intervals[i]);
        } else if (no_overlap.back()[1] > intervals[i][1]) {
            no_overlap.pop_back();
            no_overlap.push_back(intervals[i]);
        }
    }
    
    return intervals.size() - no_overlap.size();
}
