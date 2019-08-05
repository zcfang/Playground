#include <assert.h>

/**
 * Problem from LeetCode 70: Climbing Stairs. You can find the problem
 * <a href="https://leetcode.com/problems/climbing-stairs/">
 * here</a>.
 *
 * @param[in] x: Number of stairs
 * @returns How many distinct ways to climb a n sized stair where the step size
 * is either 1 or 2.
 */
int climb_stairs(int n);

int main(int argc, char const *argv[]) {
    int test_case_1 = 2;
    int test_case_2 = 3;

    assert(climb_stairs(test_case_1) == 2);
    assert(climb_stairs(test_case_2) == 3);

    return 0;
}

int climb_stairs(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 2;
        
    return (climb_stairs(n - 3) + 2 * climb_stairs(n - 2));
}