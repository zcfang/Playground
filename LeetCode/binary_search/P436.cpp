#include <vector>
#include <map>
#include <assert.h>

/**
 * Problem from LeetCode 436: Find Right Interval. You can find the problem
 * <a href="https://leetcode.com/problems/find-right-interval/">
 * here</a>.
 *
 * @param[in] intervals: A vector of intervals
 * @returns For any interval i, you need to store the minimum interval j's
 * index, which means that the interval j has the minimum start point to build
 * the "right" relationship for interval i. If the interval j doesn't exist,
 * store -1 for the interval i. Finally, you need output the stored value of
 * each interval as an array.
 * -1.
 */
std::vector<int> find_right_interval(std::vector<std::vector<int>> &intervals);

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> test_case_1 = {{3,4},{2,3},{1,2}};
    std::vector<int >solution = {-1,0,1};

    assert(find_right_interval(test_case_1) == solution);

    return 0;
}

std::vector<int> find_right_interval(std::vector<std::vector<int>> &intervals)
{
    int m = intervals.size() - 1;
    std::vector<int> output(intervals.size(), -1);
    std::map<std::pair<int, int>, int> index;

    for (std::size_t i = 0; i < intervals.size(); i++) {
        index[{intervals[i][0], intervals[i][1]}] = i;
    }
    std::sort(intervals.begin(), intervals.end());
    for (int i = 0; i < m; i++) {
        int pos = -1;
        int value = INT_MAX;
        int key = index[{intervals[i][0], intervals[i][1]}];
        int start = i + 1;
        int end = intervals.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (intervals[mid][0] >= intervals[i][1]) {
                pos = index[{intervals[mid][0], intervals[mid][1]}];
                value = intervals[mid][0];
                end = mid - 1;
            } else if (intervals[mid][0] < intervals[i][1]) {
                start = mid + 1;
            }
        }
        output[key] = pos;
    }

    return output;
}
