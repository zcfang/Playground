#include <vector>
#include <algorithm>
#include <assert.h>

/**
 * Problem from LeetCode 1094: Car Pooling. You can find the
 * problem <a href="https://leetcode.com/problems/car-pooling/">
 * here</a>.
 *
 * @param[in] trips: A list of trips,
 * trip[i] = [num_passengers, start_location, end_location] contains
 * information about the i-th trip: the number of passengers that must be
 * picked up, and the locations to pick them up and drop them off. The
 * locations are given as the number of kilometers due east from your vehicle's
 * initial location.
 * @returns True if and only if it is possible to pick up and drop off all
 * passengers for all the given trips. 
 */
bool car_pooling(std::vector<std::vector<int>> &trips, int capacity);

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> test_case_1 = {{2,1,5},
                                                 {3,3,7}};
    int capacity = 4;

    assert(!car_pooling(test_case_1, capacity));

    return 0;
}

bool car_pooling(std::vector<std::vector<int>> &trips, int capacity) {
    std::vector<std::pair<int, int>> min_heap;
    std::sort(trips.begin(),
              trips.end(),
              [](const std::vector<int> &first,
                 const std::vector<int> &second) {
                  return first[1] < second[1];
              });
    for (const std::vector<int> trip : trips) {
        while (!min_heap.empty() && min_heap.front().first <= trip[1]) {
            capacity += min_heap.front().second;
            std::pop_heap(min_heap.begin(), min_heap.end(),
                          std::greater<std::pair<int,int>>{});
            min_heap.pop_back();
        } 
        if (trip[0] <= capacity) {
            capacity -= trip[0];
            min_heap.push_back({trip[2], trip[0]});
            std::push_heap(min_heap.begin(), min_heap.end(),
                           std::greater<std::pair<int,int>>{});
        } else return false;
    }

    return true;
}
