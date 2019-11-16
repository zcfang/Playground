#include <vector>
#include <set>
#include <assert.h>

/**
 * Problem from LeetCode 202: Happy Number. You can find the
 * problem <a href="https://leetcode.com/problems/happy-number/">
 * here</a>.
 *
 * @param[in] n: A number
 * @returns A boolean indicating whether n is a "happy number"
 */
bool is_happy(int n);

int main(int argc, char const *argv[]) {
    int test_case_1 = 19;

    assert(is_happy(test_case_1));

    return 0;
}

bool is_happy(int n) {
    int sum = 0;
    std::set<int> checked_values;

    checked_values.insert(n);
    while (true) {
        while (n) {
            sum += ((n % 10) * (n % 10));
            n /= 10;
        }
        if (sum == 1) {
            return true;
        } else if (checked_values.count(sum)) {
            return false;
        } else {
            n = sum;
            sum = 0;
            checked_values.insert(n);
        }
    }

    return true;
}
