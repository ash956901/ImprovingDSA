class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0;
        int n=arr.size()-1;
        int r=n;
        int mid=l+(r-l)/2;
        while(l<=r){
            int missingCount=arr[mid]-(mid+1);
            if(missingCount<k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
            mid=l+(r-l)/2;
        }

        return l+k;
    }
};