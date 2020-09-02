#include <vector>
#include <string>
#include <assert.h>

/**
 * Problem from LeetCode 949: Largest Time for Given Digits. You can find the
 * problem
 * <a href="https://leetcode.com/problems/largest-time-for-given-digits/">
 * here</a>.
 *
 * @param[in] A: An array of four digits
 * @returns The largest 24 hour time that can be made.
 */
std::string largest_time_from_digits(std::vector<int> &A);

/**
 * Compute all possible valid time permutation 
 *
 * @param[in] first: Index to fix when computing a particular permutation
 * @param[in] A: An array of four digits
 * @param[in,out] output: Largest 24 hour time
 */
void permutation(int first, std::vector<int> &A, std::string &output);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1 = {1,2,3,4};
    std::string solution = "23:41";

    assert(largest_time_from_digits(test_case_1) == solution);

    return 0;
}

void permutation(int first, std::vector<int> &A, std::string &output) {
    if (first == A.size()) {
        int hour = A[0] * 10 + A[1];
        int minute = A[2] * 10 + A[3];
        int total_min = hour * 60 + minute;
        if (hour < 24 && minute < 60) {
            int curr_hour = output.size() ?
                            (output[0] - '0') * 10 + (output[1] - '0') : -1;
            int curr_minute = output.size() ?
                              (output[3] - '0') * 10 + (output[4] - '0') : -1;
            int curr_total = curr_hour * 60 + curr_minute;
            if (curr_total < total_min) {
                output = "";
                output.push_back(A[0] + '0');
                output.push_back(A[1] + '0');
                output.push_back(':');
                output.push_back(A[2] + '0');
                output.push_back(A[3] + '0');
            }
        }
        return;
    }
    for (int i = first; i < A.size(); i++) {
        std::swap(A[first], A[i]);
        permutation(first + 1, A, output);
        std::swap(A[first], A[i]);
    }
}

std::string largest_time_from_digits(std::vector<int> &A) {
    std::string output = "";

    permutation(0, A, output);

    return output;
}
