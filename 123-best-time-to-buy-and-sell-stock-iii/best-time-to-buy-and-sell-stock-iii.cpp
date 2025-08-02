class Solution {
public:
    int solve(int idx, int canBuy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (idx == prices.size() || cap == 0) return 0;

        if (dp[idx][canBuy][cap] != -1) return dp[idx][canBuy][cap];

        int profit = 0;
        if (canBuy) {
            int buy = -prices[idx] + solve(idx + 1, 0, cap, prices, dp);
            int skip = solve(idx + 1, 1, cap, prices, dp);
            profit = max(buy, skip);
        } else {
            int sell = prices[idx] + solve(idx + 1, 1, cap - 1, prices, dp);
            int hold = solve(idx + 1, 0, cap, prices, dp);
            profit = max(sell, hold);
        }

        return dp[idx][canBuy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 2, prices, dp); 
    }
};
