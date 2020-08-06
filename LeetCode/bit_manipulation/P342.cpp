#include <math.h>
#include <assert.h>

/**
 * Problem from LeetCode 342: Power of Four. You can find the problem
 * <a href="https://leetcode.com/problems/power-of-four/">
 * here</a>.
 *
 * @param[in] num: A signed 32 bit number
 * @returns A boolean indicating whether n is a power of four
 */
bool is_power_of_four(int num);

int main(int argc, char const *argv[]) {
    int test_case_1 = 16;
    int test_case_2 = 5;

    assert(is_power_of_four(test_case_1));
    assert(!is_power_of_four(test_case_2));

    return 0;
}

bool is_power_of_four(int num) {
    if (num <= 0 || (num & (num - 1)) != 0) {
        return false;
    }
    double count = log2(num);
    
    return !((int) count % 2);
}
