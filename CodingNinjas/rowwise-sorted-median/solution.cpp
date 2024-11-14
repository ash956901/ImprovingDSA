
#include <bits/stdc++.h>
using namespace std;

int countElements(vector<vector<int>> &matrix, int mid) {
    int count = 0;
    for (int i = 0; i < matrix.size(); i++) {
        count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
    }
    return count;
}

int median(vector<vector<int>> &matrix, int n, int m) {
    int low = INT_MAX;
    int high = INT_MIN;
    // find the minimum and maximum for the search space
    for (int i = 0; i < n; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }

    int required = (n * m) / 2;  // half of total elements
    // binary search on the low to high search space
    while (low < high) {
        int mid = low + (high - low) / 2;
        int elements = countElements(matrix, mid);
        if (elements < required) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << median(matrix, n, m) << endl;
    return 0;
}
