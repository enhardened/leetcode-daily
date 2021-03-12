// Problem: https://leetcode.com/explore/item/3668
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max_coins = amount + 1;
        vector<int> dp(amount + 1, max_coins);
        
        dp[0] = 0;
        
        for (int i = 0; i < max_coins; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] > i)
                    continue;
                
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        
        return dp[amount] > amount
            ? -1
            : dp[amount];
    }
};
