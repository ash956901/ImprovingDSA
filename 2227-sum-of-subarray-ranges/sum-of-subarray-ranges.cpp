class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sumMax = 0, sumMin = 0;
        stack<int> st;

        
        for (int i = 0; i <= n; ++i) {
            
            int curr = (i < n ? nums[i] : INT_MAX);
            while (!st.empty() && nums[st.top()] <= curr) {
                int mid = st.top(); st.pop();
                int left  = mid - (st.empty() ? -1 : st.top());
                int right = i - mid;
                sumMax += (long long)nums[mid] * left * right;
            }
            st.push(i);
        }

        
        while (!st.empty()) st.pop();

       
        for (int i = 0; i <= n; ++i) {
            
            int curr = (i < n ? nums[i] : INT_MIN);
            while (!st.empty() && nums[st.top()] >= curr) {
                int mid = st.top(); st.pop();
                int left  = mid - (st.empty() ? -1 : st.top());
                int right = i - mid;
                sumMin += (long long)nums[mid] * left * right;
            }
            st.push(i);
        }

        return sumMax - sumMin;
    }
};
