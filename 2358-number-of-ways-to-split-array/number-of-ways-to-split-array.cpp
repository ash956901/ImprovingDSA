class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
       long long rSum=0;
       for(auto i:nums){
        rSum+=i;
       }

       long long  lSum=0;
       long long  count=0;
       for(int i=0;i<nums.size()-1;i++){
            lSum+=nums[i];
            if(lSum>=rSum-lSum) count++;
       }

       return count;

    }
};