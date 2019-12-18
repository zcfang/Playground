#include <vector>
#include <algorithm>
#include <assert.h>

/**
 * Problem from LeetCode 1046: Last Stone Weight. You can find the
 problem <a href="https://leetcode.com/problems/last-stone-weight/">
 * here</a>.
 *
 * @param[in] stones: A vector representing the weight of stones
 * @returns The weight of the remaining stone. If no stone remains, return 0.
 */
int last_stone_weight(std::vector<int> &stones);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{2,7,4,1,8,1};

    assert(last_stone_weight(test_case_1) == 1);

    return 0;
}

int last_stone_weight(std::vector<int> &stones) {
    int first;
    int second;
    int output;

    std::make_heap(stones.begin(), stones.end());
    while (stones.size() > 1) {
        first = stones[0];
        std::pop_heap(stones.begin(), stones.end());
        stones.pop_back();
        second = stones[0];
        std::pop_heap(stones.begin(), stones.end());
        stones.pop_back();
        if (first - second) {
            stones.push_back(first - second);
            std::push_heap(stones.begin(), stones.end());
        }
    }
    
    output = stones.size() ? stones[0] : 0;
    
    return output;
}
