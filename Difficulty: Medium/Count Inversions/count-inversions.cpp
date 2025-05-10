//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to count inversions in the array.
    int merge(vector<int> &arr,int low ,int mid ,int high){
        vector<int> temp;
        int i=low;
        int j=mid+1;
        int count=0;
        
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
                count+=(mid-i+1);
            }   
        }
        
        while(i<=mid){
                temp.push_back(arr[i]);
                i++;
        }
        
        while(j<=high){
                temp.push_back(arr[j]);
                j++;
        }
        
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
        
        return count;
    }
    int mergeInversion(vector<int> &arr,int low ,int high){
        if(low>=high) return 0;
        int count=0;
        int mid=(low+high)/2;
        count+=mergeInversion(arr,low,mid);
        count+=mergeInversion(arr,mid+1,high);
        count+=merge(arr,low,mid,high);
        return count;
    }
    int inversionCount(vector<int> &arr) {
        
        return mergeInversion(arr,0,arr.size()-1);
        
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends