#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 122: Best Time to Buy and Sell Stock II. You can find
 * the problem
 * <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/">
 * here</a>.
 *
 * @param[in] prices: A vector of prices
 * @returns Maximum profit when buying and selling at different instances
 */
int max_profit(std::vector<int> &prices);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{7,1,5,3,6,4};
    std::vector<int> test_case_2{1,2,3,4,5};
    std::vector<int> test_case_3{7,6,4,3,1};

    assert(max_profit(test_case_1) == 7);
    assert(max_profit(test_case_2) == 4);
    assert(max_profit(test_case_3) == 0);

    return 0;
}

int max_profit(std::vector<int> &prices) {
    if (!prices.size()) return 0;
    std::size_t min_price = prices[0];
    std::size_t profit = 0;
    
    for (int price : prices) {
        min_price = price < min_price ? price : min_price;
        if (price > min_price) {
            profit += (price - min_price);
            min_price = price;
        }
    }
    
    return profit;
}