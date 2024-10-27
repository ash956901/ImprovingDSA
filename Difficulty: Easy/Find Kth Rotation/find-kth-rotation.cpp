//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int getPeak(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;
        int mid = s + (e - s) / 2;
        while (s <e) {
            if (arr[mid] >= arr[0] && arr[mid] >=arr[mid + 1]) {
                s = e = mid;
                break;
            } else if (arr[mid] >=arr[0] && arr[mid] <=arr[mid + 1]) {
                s = mid + 1;
            } else if (arr[mid] <=arr[0] && arr[mid] <=arr[mid + 1]) {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return s;
    }
 
    int findKRotation(vector<int> &arr) {
        int index=getPeak(arr);
        if(index==arr.size()-1) return 0;
        return index+1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends