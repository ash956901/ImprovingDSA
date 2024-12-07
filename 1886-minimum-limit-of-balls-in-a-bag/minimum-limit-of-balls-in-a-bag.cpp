class Solution {
public:
    int solve(vector<int>& nums,int maxOperations,int penalty){
        int n=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>penalty){
                double quotient=ceil(nums[i]/(double)penalty);
                n+=quotient-1;
            }
        }
        return n<=maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left=1;
        int right=*max_element(nums.begin(),nums.end());

        while(left<right){
            int mid=left+(right-left)/2;
            if(solve(nums,maxOperations,mid)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }

        return left;
    }
};