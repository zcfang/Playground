#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 11: Container With Most Water. You can find the
 * problem
 * <a href="https://leetcode.com/problems/container-with-most-water/">
 * here</a>.
 *
 * @param[in] height: A vector containing height values
 * @returns Given n non-negative integers a1, a2, ..., an , where each
 * represents a point at coordinate (i, ai). n vertical lines are drawn such
 * that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines,
 * which together with x-axis forms a container, such that the container
 * contains the most water.
 */
int max_area(std::vector<int> &height);

int main(int argc, char const *argv[]) {
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};

    assert(max_area(height) == 49);

    return 0;
}

int max_area(std::vector<int> &height) {
    int output = 0;
    int i = 0;
    int j = height.size() - 1;
    
    while (i <= j) {
        int area;
        if (height[i] < height[j]) {
            area = (j - i) * height[i];
            i++;
        } else {
            area = (j - i) * height[j];
            j--;
        }
        output = area > output ? area : output;
    }
    
    return output;
}
