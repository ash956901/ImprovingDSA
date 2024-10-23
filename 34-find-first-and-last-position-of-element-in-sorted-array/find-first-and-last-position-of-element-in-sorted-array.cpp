class Solution {
public:
    int searchStart(vector<int>& arr, int x) {
        int s = 0;
        int e = arr.size() - 1;
        int mid = s + (e - s) / 2;
        int ans = -1;
        while (s <= e) {
            if (arr[mid] == x){
                ans=mid;
                e=mid-1;
            }
            else if (x > arr[mid]) {
                s = mid + 1;
            } else if (x < arr[mid]) {
                e = mid - 1;
            }

            mid = s + (e - s) / 2;
        }

        return ans;
    }
    int searchEnd(vector<int>& arr, int x) {
        int s = 0;
        int e = arr.size() - 1;
        int mid = s + (e - s) / 2;
        int ans = -1;
        while (s <= e) {
            if (arr[mid] == x){
                ans=mid;
                s=mid+1;
            }
            else if (x > arr[mid]) {
                s = mid + 1;
            } else if (x < arr[mid]) {
                e = mid - 1;
            }

            mid = s + (e - s) / 2;
        }

        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0]=searchStart(nums,target);
        ans[1]=searchEnd(nums,target);
        return ans;
    }
};