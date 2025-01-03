class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> sumArr(nums.size(),0);
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sumArr[i]=sum;
        }

       
        int count=0;
        int n=nums.size()-1;
        for(int i=0;i<nums.size()-1;i++){
            if(sumArr[i]>=sumArr[n]-sumArr[i])count++;
        }
        return count;
    }
};