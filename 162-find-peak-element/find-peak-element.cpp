class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        if(arr.size()==1) return 0;
        int n=arr.size()-1;
        if(arr[0]>arr[1]) return 0;
        else if(arr[n]>arr[n-1]) return n;
        int s=1;
        int e=arr.size()-2;
        int mid=s+(e-s)/2;
        while(s<e){
          if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
            return mid;
          }
          else if(arr[mid-1]<=arr[mid]&& arr[mid]<=arr[mid+1]){
            s=mid+1;
          }
          else{
            e=mid-1;
          }
          mid=s+(e-s)/2;
        }

        return mid;
    }
};