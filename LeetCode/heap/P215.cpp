#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <assert.h>

/**
 * Problem from LeetCode 215: Kth Largest Element in an Array. You can find the
 * problem
 * <a href="https://leetcode.com/problems/kth-largest-element-in-an-array/">
 * here</a>.
 *
 * @param[in] nums: A vector of unsorted numbers
 * @param[in] k: kth largest number
 * @returns The kth largest element in an unsorted array. Note that it is the
 * kth largest element in the sorted order, not the kth distinct element.
 */
int find_kth_largest(std::vector<int> &nums, int k);

class Heap {
public:
    std::vector<int> heap_array;
    /**
     * Heap constructor
     *
     * @param[in] array: An unsorted array of numbers to convert into a heap
     */
    Heap(const std::vector<int> array) {
        heap_array = array;
    }
    ~Heap() {};

    /**
     * Return size of heap
     *
     * @returns Size of heap
     */
    int size() {
        return heap_array.size();
    }

    /**
     * Convert unsorted input array into a heap
     */
    void make_heap() {
        int start = size() / 2;
        for (int i = start; i >= 0; i--) {
            heapify_down(i);
        }
    }

    /**
     * Return root element of input heap
     *
     * @returns Root element
     */
    int top() {
        try {
            int value = heap_array.at(0);

            return value;
        } catch (const std::out_of_range &oor) {
            std::cerr << "Out of Range Error: " << oor.what() << "\n";
        }

        return -1;
    }

    /**
     * Remove root element of input heap
     */
    void pop_heap() {
        try {
            if (size() == 0) {
                throw std::out_of_range("Out of Range Error: ");
            }
            heap_array[0] = heap_array.back();
            heap_array.pop_back();
            heapify_down(0);
        } catch (const std::out_of_range &oor){
            std::cerr << oor.what() << "\n";
        }
    }

    /**
     * Push element to heap
     *
     * @param[in] value: Value to push onto heap
     */
    void push_heap(int value) {
        heap_array.push_back(value);
        heapify_up(size() - 1);
    }
private:
    /**
     * Get parent index
     *
     * @param[in] index: Node index
     * @returns Parent index
     */
    int get_parent(int index) {
        return (index - 1) / 2;
    }

    /**
     * Get left child index
     *
     * @param[in] index: Node index
     * @returns Left child index
     */
    int get_left_child(int index) {
        return (2 * index) + 1;
    }

    /**
     * Get right child index
     *
     * @param[in] index: Node index
     * @returns Right child index
     */
    int get_right_child(int index) {
        return (2 * index) + 2;
    }

    /**
     * Maintain heap structure of given index
     *
     * @param[in] index: Node index to maintain heap property
     */
    void heapify_down(int index) {
        int left = get_left_child(index);
        int right = get_right_child(index);
        int largest = index;

        if (left < size() && heap_array[index] < heap_array[left]) {
            largest = left;
        }
        if (right < size() && heap_array[largest] < heap_array[right]) {
            largest = right;
        }
        if (largest != index) {
            std::swap(heap_array[index], heap_array[largest]);
            heapify_down(largest);
        }
    }

    /**
     * Maintain heap structure of given index in upward direction
     *
     * @param[in] index: Node index to maintain heap property
     */
    void heapify_up(int index) {
        int parent = get_parent(index);

        if (index && heap_array[parent] < heap_array[index]) {
            std::swap(heap_array[index], heap_array[parent]);
            heapify_up(parent);
        }
    }
};

int main(int argc, char const *argv[]) {
    std::vector<int> nums{3,2,1,5,6,4};
    int k = 2;

    assert(find_kth_largest(nums, k) == 5);

    return 0;
}

int find_kth_largest(std::vector<int> &nums, int k) {
    Heap heap(nums);

    heap.make_heap();
    for (int i = 0; i < k - 1; i++) {
        heap.pop_heap();
    }

    return heap.top();
}
