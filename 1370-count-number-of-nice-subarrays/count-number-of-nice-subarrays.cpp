class Solution {
public:
    int solve(vector<int>& nums, int k){
        int odd=0;
        int i=0;
        int res=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]%2!=0) odd++;
            while(odd>k){
                if(nums[i]%2!=0) odd--;
                i++;
            }
                res+=(j-i+1);
            
            
        }

        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};