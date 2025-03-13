class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> s;
        string ans;
        int n = num.size();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && k != 0 && (num[i] - '0' < num[s.top()] - '0')) {
                s.pop();
                k--;
            }
            s.push(i);
        }

        // Make string from leftover stack
        while (!s.empty()) {
            ans.push_back(num[s.top()]);
            s.pop();
        }
        reverse(ans.begin(), ans.end());

        if (k != 0) {
            // Means the number was increasing, so remove the last k digits
            while (k != 0) {
                ans.pop_back();
                k--;
            }
        }
        
        // Remove leading zeros from the answer
        int z = 0;
        while (z < ans.size() && ans[z] == '0') {
            z++;
        }
        string temp = ans.substr(z);
        return temp == "" ? "0" : temp;
    }
};
