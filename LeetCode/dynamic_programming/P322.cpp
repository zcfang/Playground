#include <vector>
#include <assert.h>

/**
 * Problem from LeetCode 322: Coin Change. You can find the
 * problem
 * <a href="https://leetcode.com/problems/coin-change/">
 * here</a>.
 *
 * @param[in] coins: A vector of coin denominations
 * @param[in] amount: Money amount
 * @returns You are given coins of different denominations and a total amount
 * of money amount. Write a function to compute the fewest number of coins that
 * you need to make up that amount. If that amount of money cannot be made up
 * by any combination of the coins, return -1.
 */
int coin_change(std::vector<int> &coins, int amount);

int main(int argc, char const *argv[]) {
    std::vector<int> test_case_1{1,2,5};
    int amount_1 = 11;

    assert(coin_change(test_case_1, amount_1) == 3);

    return 0;
}

int coin_change(std::vector<int> &coins, int amount) {
    std::vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (const int coin : coins) {
            if (i >= coin) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    dp[amount] = dp[amount] > amount ? -1 : dp[amount];

    return dp.back();
}
