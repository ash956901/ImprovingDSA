//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
       if(n==1) return 1;
       if(n==0) return 0;
       long long int l=0;
       long long int r=n;
       long long int mid=l+(r-l)/2;
       while(l<r){
           if(mid*mid>n){
             r=mid;
           }
           else{
               l=mid+1;
           }
           mid=l+(r-l)/2;
       }
       
      return l-1;
      
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends