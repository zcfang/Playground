#include <vector>
#include <string>
#include <assert.h>

/**
 * Problem from LeetCode 1291: Sequential Digits. You can find the problem
 * <a href="https://leetcode.com/problems/sequential-digits/">
 * here</a>.
 *
 * @param[in] low: Lower bound
 * @param[in] high: Upper bound
 * @returns A sorted list of all the integers in the range [low, high]
 * inclusive that have sequential digits.
 */
std::vector<int> sequential_digits(int low, int high);

int main(int argc, char const *argv[]) {
    int low = 1000;
    int high = 13000;
    std::vector<int> solution = {1234,2345,3456,4567,5678,6789,12345};

    assert(sequential_digits(low, high) == solution);

    return 0;
}

std::vector<int> sequential_digits(int low, int high) {
    int low_len = std::to_string(low).size();
    int high_len = std::to_string(high).size();
    int n = 10;
    std::string max_val = "123456789";
    std::vector<int> output;

    for (int i = low_len; i <= high_len; i++) {
        for (int j = 0; j < n - i; j++) {
            int num = std::stoi(max_val.substr(j, i));
            if (num >= low && num <= high) {
                output.push_back(num);
            }
            if (num > high)
                break;
        }            
    }

    return output;
}
