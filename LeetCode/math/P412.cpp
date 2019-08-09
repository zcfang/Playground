#include <vector>
#include <string>
#include <assert.h>

/**
 * Problem from LeetCode 412: Fizz Buzz. You can find the problem
 * <a href="https://leetcode.com/problems/fizz-buzz/">
 * here</a>.
 *
 * @param[in] n: An integer
 * @returns A boolean indicating whether n is a power of three
 */
std::vector<std::string> fizz_buzz(int n);

int main(int argc, char const *argv[]) {
    std::vector<std::string> case_1_result = {"1", "2", "Fizz"};

    assert(fizz_buzz(3) == case_1_result);

    return 0;
}

std::vector<std::string> fizz_buzz(int n) {
    std::vector<std::string> result;
    
    for (std::size_t i = 0; i < n; i++) {
        if (!((i + 1) % 3) && !((i + 1) % 5)) result.push_back("FizzBuzz");
        else if (!((i + 1) % 3)) result.push_back("Fizz");
        else if (!((i + 1) % 5)) result.push_back("Buzz");
        else result.push_back(std::to_string(i + 1));
    }

    return result;
}
