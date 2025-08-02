class Solution {
public:
    int helper(vector<int> &nums,int start,int end){
        int prev1=nums[start];
        int prev2=0;
        for(int i=start+1;i<=end;i++){
            int pick=nums[i]+(i>start+1?prev2:0);
            int notpick=prev1;
            int curr=max(pick,notpick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(helper(nums,0,n-2),helper(nums,1,n-1));
    }
};