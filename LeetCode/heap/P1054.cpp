#include <vector>
#include <unordered_map>
#include <algorithm>
#include <assert.h>

/**
 * Problem from LeetCode 1054: Distant Barcodes. You can find the
 * problem <a href="https://leetcode.com/problems/distant-barcodes/">
 * here</a>.
 *
 * @param[in] stones: A vector representing the weight of stones
 * @returns The weight of the remaining stone. If no stone remains, return 0.
 */
std::vector<int> rearrange_barcodes(std::vector<int> &barcodes);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{1,1,1,2,2,2};
    std::vector<int> solution{2,1,2,1,2,1};

    assert(rearrange_barcodes(test_case_1) == solution);

    return 0;
}

std::vector<int> rearrange_barcodes(std::vector<int> &barcodes) {
    if (barcodes.size() == 1) return barcodes;
    std::vector<int> output;
    std::unordered_map<int, int> numbers;
    std::vector<std::pair<int, int>> heap; 

    for (const int number : barcodes) {
        numbers[number]++;            
    }
    for (const std::pair<int, int> freq : numbers) {
        heap.push_back({freq.second, freq.first});
    }
    std::make_heap(heap.begin(), heap.end());

    while (!heap.empty()) {
        std::pair<int, int> first = heap.front();
        std::pop_heap(heap.begin(), heap.end());
        heap.pop_back();
        std::pair<int, int> second = heap.front();
        std::pop_heap(heap.begin(), heap.end());
        heap.pop_back();
        int limit = heap.empty() ? 0 : heap.front().first;
        while (first.first + second.first != limit) {
            if (first.first > 0 && (output.empty() ||
                output.back() != first.second)) {
                output.push_back(first.second);
                first.first--;
            }
            if (first.first + second.first == limit) break;
            if (second.first > 0 && (output.empty() ||
                output.back() != second.second)) {
                output.push_back(second.second);
                second.first--;
            }
        }
        if (first.first > 0) {
            heap.push_back(first);
            std::push_heap(heap.begin(), heap.end());
        }
        if (second.first > 0) {
            heap.push_back(second);
            std::push_heap(heap.begin(), heap.end());
        }
    }

    return output;
}
