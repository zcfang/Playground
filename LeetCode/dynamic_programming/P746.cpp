#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 746: Min Cost Climbing Stairs. You can find the
 problem <a href="https://leetcode.com/problems/min-cost-climbing-stairs/">
 * here</a>.
 *
 * @param[in] cost: A vector of numbers representing the cost at each step. If
 * this step is taken, you can either climb one or two steps
 * @returns An integer indicating the minimum cost to reach the top of a stair
 */
int min_cost_climbing_stairs(std::vector<int> &cost);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{10,15,20};
    std::vector<int> test_case_2{1,100,1,1,1,100,1,1,100,1};

    assert(min_cost_climbing_stairs(test_case_1) == 15);
    assert(min_cost_climbing_stairs(test_case_2) == 6);

    return 0;
}

int min_cost_climbing_stairs(std::vector<int> &cost) {
    if(cost.size() == 2) return std::min(cost[0], cost[1]);
    std::vector<int> total(cost.size());
    total[0] = 0;
    total[1] = std::min(cost[0], cost[1]);
    
    for (std::size_t i = 2; i < cost.size(); i++) {
        total[i] = std::min(cost[i] + total[i - 1],
                            cost[i - 1] + total[i - 2]);
    }
    
    return total.back();
}
