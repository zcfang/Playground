#include <vector>
#include <algorithm>
#include <assert.h>

/**
 * Problem from LeetCode 253: Meeting Rooms II. You can find the
 * problem <a href="https://leetcode.com/problems/meeting-rooms-ii/">
 * here</a>.
 *
 * @param[in] intervals: An array of meeting time intervals consisting of start
 * and end times [[s1,e1],[s2,e2],...] (si < ei).
 * @returns The minimum number of conference rooms required.
 */
int min_meeting_rooms(std::vector<std::vector<int>> &intervals);

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> test_case_1 = {{0, 30},{5, 10},{15, 20}};
    int solution = 2;

    assert(min_meeting_rooms(test_case_1) == solution);

    return 0;
}

int min_meeting_rooms(std::vector<std::vector<int>> &intervals) {
    std::vector<int> heap;

    std::sort(intervals.begin(), intervals.end());

    for (const std::vector<int> interval : intervals) {
        if (heap.empty() || heap.front() > interval[0]) {
            heap.push_back(interval[1]);
            std::push_heap(heap.begin(), heap.end(), std::greater<int>());
        } else {
            std::pop_heap(heap.begin(), heap.end(), std::greater<int>());
            heap.pop_back();
            heap.push_back(interval[1]);
            std::push_heap(heap.begin(), heap.end(), std::greater<int>());
        }
    }
    return heap.size();
}
