class Solution {
public:
    int n;
    vector<int> prices;
    vector<vector<vector<int>>> dp;
    
    int solve(int idx, int canBuy, int cap) {
        if (idx == n || cap == 0) return 0;
        
        if (dp[idx][canBuy][cap] != -1) 
            return dp[idx][canBuy][cap];
        
        int profit;
        if (canBuy) {
            int buy = -prices[idx] + solve(idx + 1, 0, cap);
            int skip = solve(idx + 1, 1, cap);
            profit = max(buy, skip);
        } else {
            int sell = prices[idx] + solve(idx + 1, 1, cap - 1);
            int hold = solve(idx + 1, 0, cap);
            profit = max(sell, hold);
        }
        return dp[idx][canBuy][cap] = profit;
    }

    int maxProfit(int k, vector<int>& pricesInput) {
        prices = pricesInput;
        n = prices.size();
        dp.resize(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(0, 1, k);
    }
};
