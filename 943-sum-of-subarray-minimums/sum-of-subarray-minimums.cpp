#define MOD 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        stack<int> st; 
        int n = arr.size();

        for (int i = 0; i < n; i++) {
          
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                int mid = st.top(); 
                st.pop();

                int left = st.empty() ? mid + 1 : mid - st.top();
                int right = i - mid;

               
                sum = (sum + (long long)left * right % MOD * arr[mid] % MOD) % MOD;
            }

            st.push(i);
        }

      
        while (!st.empty()) {
            int mid = st.top();
            st.pop();

            int left = st.empty() ? mid + 1 : mid - st.top();
            int right = n - mid;

            sum = (sum + (long long)left * right % MOD * arr[mid] % MOD) % MOD;
        }

        return (int)sum;
    }
};
