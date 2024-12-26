class Solution {
public:
    int solve(vector<int>& nums,int i,int target){
        if(i>=nums.size() && target==0){
            return 1;
           
        }
        else if(i>=nums.size()) return 0;

     
        int a=solve(nums,i+1,target-nums[i]);
        int b=solve(nums,i+1,target+nums[i]);

        return (a+b);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,0,target);
    }
};