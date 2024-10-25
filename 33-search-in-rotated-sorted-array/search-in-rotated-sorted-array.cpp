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

    int search(vector<int>& nums, int target,int start,int end) {
        int s=start;
        int e=end;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                return mid;
            }
            else if(target>nums[mid]){
                s=mid+1;
            }
            else if(target<nums[mid]){
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }

        return -1;
        
    }

    int search(vector<int>& nums, int target) {
        int peak = getPeak(nums);
        int firstPart=search(nums,target,0,peak);
        int secondPart=search(nums,target,peak+1,nums.size()-1);
        if(firstPart==-1 && secondPart==-1 ) return -1;
        else if(firstPart>=0) return firstPart;
            return secondPart;
        

    }
};