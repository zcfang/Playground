#include <vector>
#include <map>
#include <assert.h>

/**
 * Problem from LeetCode 1103: Distribute Candies to People. You can find the
 * problem
 * <a href="https://leetcode.com/problems/distribute-candies-to-people/">
 * here</a>.
 *
 * @param[in] candies: Number of candies
 * @param[in] num_people: Number of people
 * @returns A vector (of length `num_people` and sum `candies`) that represents
 * the final distribution of candies.
 */
std::vector<int> distribute_candies(int candies, int num_people);

int main(int argc, char const *argv[]) {
    int candies = 7;
    int num_people = 4;
    std::vector<int> solution = {1,2,3,1};

    assert(distribute_candies(candies, num_people) == solution);
    return 0;
}

std::vector<int> distribute_candies(int candies, int num_people) {
    std::vector<int> output(num_people, 0);
    int count = 0;
    while (candies) {
        int index = count % num_people;
        int add = count >= candies ? candies : count + 1;
        output[index] += add;
        candies -= add;
        count++;
    }

    return output;
}
