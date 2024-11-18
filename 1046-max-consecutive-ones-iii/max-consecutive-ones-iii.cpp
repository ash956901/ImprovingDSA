class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count=0;
        int zeroes=0;
        int i=0;
        int maxi=INT_MIN;
        for(int j=0;j<nums.size();j++){
            count++;
            if(nums[j]==0) zeroes++;
            while(zeroes>k){
                if(nums[i]==0) zeroes--;
                count--;
                i++;
            }
            maxi=max(maxi,count);
        }

        return maxi;
    }
};