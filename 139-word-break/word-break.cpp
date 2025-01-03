class Solution {
public:
    bool solve(string &s, int i, unordered_map<string, bool> &dict, vector<int> &dp) {
        if (i == s.size()) return true; 
        if (dp[i] != -1) return dp[i]; 

        string temp = "";
        for (int j = i; j < s.size(); ++j) {
            temp.push_back(s[j]);
            if (dict[temp] && solve(s, j + 1, dict, dp)) {
                return dp[i] = true;
            }
        }
        return dp[i] = false; 
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_map<string, bool> dict;
        for (auto &word : wordDict) {
            dict[word] = true; 
        }

        vector<int> dp(s.size(), -1); 
        return solve(s, 0, dict, dp);
    }
};
