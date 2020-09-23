#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 134: Gas Station. You can find the
 * problem <a href="https://leetcode.com/problems/gas-station/">
 * here</a>.
 *
 * @param[in] gas: A vector representing the amount of gas at each station.
 * @param[in] cost: A vector representing the amount of gas needed to travel to
 * the next station
 * @returns The starting gas station's index if you can travel around the
 * circuit once in the clockwise direction, otherwise return -1.
 */
int can_complete_circuit(std::vector<int> &gas, std::vector<int> &cost);

int main(int argc, char const *argv[]) {
    std::vector<int> gas = {1,2,3,4,5};
    std::vector<int> cost = {3,4,5,1,2};
    int solution = 3;

    assert(can_complete_circuit(gas, cost) == solution);

    return 0;
}

int can_complete_circuit(std::vector<int> &gas, std::vector<int> &cost) {
    int output = -1;
    int tank = 0;
    int net_dist = 0;

    for (std::size_t i = 0; i < gas.size(); i++) {
        tank += gas[i] - cost[i];
        net_dist += gas[i] - cost[i];
        output = output == -1 && tank >= 0 ? i : output;
        output = tank < 0 ? -1 : output;
        tank = tank < 0 ? 0 : tank;
    }
    output = net_dist >= 0 ? output : -1;

    return output;
}
