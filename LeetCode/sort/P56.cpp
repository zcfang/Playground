#include <vector>
#include <algorithm>
#include <assert.h>

/**
 * Problem from LeetCode 56: Merge Intervals. You can find the problem
 * <a href="https://leetcode.com/problems/merge-intervals/">
 * here</a>.
 *
 * @param[in] intervals: A collection of intervals
 * @returns A collection of merged intervals
 */
std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals);

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> test_case_1{{1,3},{2,6},{8,10},{15,18}};
    std::vector<std::vector<int>> solution{{1,6},{8,10},{15,18}};

    assert(merge(test_case_1) == solution);

    return 0;
}

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals) {
    std::vector<std::vector<int>> output;

    std::sort(intervals.begin(), intervals.end());
    for (const std::vector<int> interval : intervals) {
        if (output.empty() || output.back()[1] < interval[0]) {
            output.push_back(interval);
        } else {
            output.back()[1] = std::max(output.back()[1], interval[1]); 
        }
    }

    return output;
}
