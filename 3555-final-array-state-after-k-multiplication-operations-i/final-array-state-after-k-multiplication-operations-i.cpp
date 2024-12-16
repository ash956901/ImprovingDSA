class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {   
        for(int i=0;i<k;i++){
            int mini=INT_MAX;
            int minIndex=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]<mini){
                    mini=nums[j];
                    minIndex=j;
                }
            }
            nums[minIndex]=mini*multiplier;
        }


        return nums;
    }
};