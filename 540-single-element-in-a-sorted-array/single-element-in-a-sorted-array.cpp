class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int n=nums.size()-1;
        int e=n;
        int mid=s+(e-s)/2;
        int ans=0;
        while(s<=e){
            int so=-1;
          //find second occurence of the current element 
          if(mid-1>=0){
            if(nums[mid-1]==nums[mid]) so=mid-1;
          }
          if(mid+1<=n){
             if(nums[mid+1]==nums[mid]) so=mid+1;
          }
          if(so==-1){
            ans=nums[mid];
            break;
          }
          //check whether its odd or even and based on that move towards the single element
          so=max(so,mid);
          if(so&1) s=mid+1;
          else e=mid-1;
          mid=s+(e-s)/2;
        }
        return ans;
    }
};