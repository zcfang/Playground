#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 121: Best Time to Buy and Sell Stock. You can find the
 * problem
 * <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock/">
 * here</a>.
 *
 * @param[in] prices: A vector of stock prices
 * @returns A int representing the maximum profit
 */
int max_profit(std::vector<int> &prices);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{7,1,5,3,6,4};
    std::vector<int> test_case_2{7,6,4,3,1};

    assert(max_profit(test_case_1) == 5);
    assert(max_profit(test_case_2) == 0);

    return 0;
}

int max_profit(std::vector<int> &prices) {
    if (prices.size() == 0) return 0;

    int profit = 0;
    int min_price = prices[0];

    for (std::size_t i = 0; i < prices.size(); i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];
        } else {
            if ((prices[i] - min_price) > profit) {
                profit = prices[i] - min_price;
            }
        }
    }

    return profit;
}
