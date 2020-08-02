#include <vector>
#include <algorithm>
#include <assert.h>

/**
 * Problem from LeetCode 1029: Two City Scheduling. You can find the
 * problem <a href="https://leetcode.com/problems/two-city-scheduling/">
 * here</a>.
 *
 * @param[in] intervals: An array of meeting time intervals consisting of start
 * and end times [[s1,e1],[s2,e2],...] (si < ei).
 * @returns The minimum number of conference rooms required.
 */
int two_city_sched_cost(std::vector<std::vector<int>> &costs);

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> test_case_1 = {{259,770},
                                                 {448,54},
                                                 {926,667},
                                                 {184,139},
                                                 {840,118},
                                                 {577,469}};
    int solution = 1859;

    assert(two_city_sched_cost(test_case_1) == solution);

    return 0;
}

int two_city_sched_cost(std::vector<std::vector<int>> &costs) {
    int total_cost = 0;
    int a_count = 0;
    int b_count = 0;

    std::sort(costs.begin(), costs.end(),
             [](const std::vector<int> &first, const std::vector<int> &second) {
                int diff_a = std::abs(first[0] - first[1]);
                int diff_b = std::abs(second[0] - second[1]);
                return diff_a > diff_b;
             });

    for (const std::vector<int> cost : costs) {
        if (cost[0] < cost[1]) {
            if (a_count < costs.size() / 2) {
                total_cost += cost[0];
                a_count++;
            } else {
                total_cost += cost[1];
                b_count++;
            }
        } else {
            if (b_count < costs.size() / 2) {
                total_cost += cost[1];
                b_count++;
            } else {
                total_cost += cost[0];
                a_count++;
            }
        }
    }

    return total_cost;
}
