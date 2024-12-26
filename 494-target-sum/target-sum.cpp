class Solution {
public:
    int solve(vector<int>& nums, int i, int target, unordered_map<string, int>& memo) {
       
        if (i >= nums.size()) {
            return target == 0 ? 1 : 0;
        }
        
       
        string key = to_string(i) + "," + to_string(target);
        
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
       
        int add = solve(nums, i + 1, target - nums[i], memo);
        int subtract = solve(nums, i + 1, target + nums[i], memo);
        
        memo[key] = add + subtract;
        
        return memo[key];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo;
        return solve(nums, 0, target, memo);
    }
};
