class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (num.empty()) return ans;
        dfs(num, target, 0, 0, 0, "", ans);
        return ans;
    }

private:
    
    void dfs(const string& num,
             long long target,
             int pos,
             long long eval,
             long long multed,
             string path,
             vector<string>& ans) {
        int n = num.size();
        if (pos == n) {
            if (eval == target)
                ans.push_back(path);
            return;
        }

        
        for (int i = pos; i < n; ++i) {
           
            if (i > pos && num[pos] == '0') break;

            long long cur = stoll(num.substr(pos, i - pos + 1));
            string curStr = num.substr(pos, i - pos + 1);

            if (pos == 0) {
                dfs(num, target, i + 1, cur, cur, curStr, ans);
            } else {
                dfs(num, target, i + 1,
                    eval + cur,
                    cur,
                    path + "+" + curStr,
                    ans);
                dfs(num, target, i + 1,
                    eval - cur,
                    -cur,
                    path + "-" + curStr,
                    ans);

                dfs(num, target, i + 1,
                    eval - multed + multed * cur,
                    multed * cur,
                    path + "*" + curStr,
                    ans);
            }
        }
    }
};
