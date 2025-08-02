class Solution {
public:
    int n, fee;
    vector<int> prices;
    vector<vector<int>> dp;

    int solve(int idx, int canBuy) {
        if (idx == n) return 0;

        if (dp[idx][canBuy] != -1) return dp[idx][canBuy];

        int profit;
        if (canBuy) {
            int buy = -prices[idx] + solve(idx + 1, 0); 
            int skip = solve(idx + 1, 1);              
            profit = max(buy, skip);
        } else {
            int sell = prices[idx] - fee + solve(idx + 1, 1); 
            int hold = solve(idx + 1, 0);                     
            profit = max(sell, hold);
        }
        return dp[idx][canBuy] = profit;
    }

    int maxProfit(vector<int>& pricesInput, int feeInput) {
        prices = pricesInput;
        fee = feeInput;
        n = prices.size();
        dp.resize(n, vector<int>(2, -1));
        return solve(0, 1); 
    }
};
