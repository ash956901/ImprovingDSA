// User function template for C++

class Solution {
  public:
    bool isPossible(const vector<int>& a, int k, int limit) {
    int count = 1, sum = 0;
    for (int x : a) {
        if (x > limit) return false;
        if (sum + x > limit) {
            count++;
            sum = x;
        } else {
            sum += x;
        }
    }
    return count <= k;
}

    int minTime(vector<int>& a, int k) {
      int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0), ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(a, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
    }
};

