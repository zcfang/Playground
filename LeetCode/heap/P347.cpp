#include <vector>
#include <map>
#include <algorithm>
#include <assert.h>

/**
 * Problem from LeetCode 347: Top K Frequent Elements. You can find the
 problem <a href="https://leetcode.com/problems/top-k-frequent-elements/">
 * here</a>.
 *
 * @param[in] nums: A vector of numbers
 * @param[in] k: k most frequent element
 * @returns Given a non-empty array of integers, return the k most frequent
 * elements.
 */
std::vector<int> top_k_frequent(std::vector<int> &nums, int k);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{1,1,1,2,2,3};
    std::vector<int> solution{1,2};
    int k = 2;

    assert(top_k_frequent(test_case_1, k) == solution);

    return 0;
}

std::vector<int> top_k_frequent(std::vector<int> &nums, int k) {
    std::map<int, int> histogram;
    std::vector<std::pair<int, int>> priority_queue;
    std::vector<int> output;

    for (const int value : nums) {
        histogram[value]++;
    }

    for (std::pair<int, int> element : histogram) {
        int first = element.first;
        element.first = element.second;
        element.second = first;
        priority_queue.push_back(element);
    }

    std::make_heap(priority_queue.begin(), priority_queue.end());

    for (int i = 0; i < k; i++) {
        output.push_back(priority_queue[0].second);
        std::pop_heap(priority_queue.begin(), priority_queue.end());
        priority_queue.pop_back();
    }

    return output;
}
