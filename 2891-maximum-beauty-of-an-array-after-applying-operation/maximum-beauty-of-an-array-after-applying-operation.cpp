class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxi=0;
        int i=0;
        for(int j=0;j<nums.size();j++){
            while(nums[j]-nums[i]>2*k){
                i++;
            }   
            maxi=max(maxi,j-i+1);
        }

        return maxi;
    }
};