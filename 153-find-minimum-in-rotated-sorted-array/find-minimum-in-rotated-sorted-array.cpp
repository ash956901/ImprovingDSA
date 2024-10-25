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
    int findMin(vector<int>& nums) {
        int peak=getPeak(nums);
        if(peak==nums.size()-1){
            return nums[0];
        }
        return nums[peak+1];
    }
};