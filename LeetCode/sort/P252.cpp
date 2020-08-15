#include <vector>
#include <algorithm>
#include <assert.h>

/**
 * Problem from LeetCode 252: Meeting Rooms. You can find the
 * problem <a href="https://leetcode.com/problems/meeting-rooms/">
 * here</a>.
 *
 * @param[in] intervals: An array of meeting time intervals consisting of start
 * and end times [[s1,e1],[s2,e2],...] (si < ei).
 * @returns Returns true if a person could attend all meetings
 */
bool can_attend_meetings(std::vector<std::vector<int>> &intervals);

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> test_case_1 = {{0, 30},{5, 10},{15, 20}};

    assert(!can_attend_meetings(test_case_1));

    return 0;
}

bool can_attend_meetings(std::vector<std::vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end());
    for (std::size_t i = 1; i < intervals.size(); i++) {
        if (intervals[i - 1][1] > intervals[i][0]) return false;
    }

    return true;
}
