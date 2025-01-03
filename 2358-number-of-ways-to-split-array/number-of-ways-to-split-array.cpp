class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> backSum(nums.size(),0);
        long long sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            backSum[i]=sum;
        }

        sum=0;
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            sum+=nums[i];
            if(sum>=backSum[i+1])count++;
        }
        return count;
    }
};