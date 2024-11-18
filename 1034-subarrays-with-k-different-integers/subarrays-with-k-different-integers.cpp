class Solution {
public:
    int atMax(vector<int>& nums, int k){
        if(k<0) return 0;
        int result=0;
        int i=0;
        unordered_map<int,int> check;
        int distinct=0;
        for(int j=0;j<nums.size();j++){
            check[nums[j]]++;
            if( check[nums[j]]==1) distinct++;
            while(distinct>k){
                check[nums[i]]--;
                if(check[nums[i]]==0) distinct--;
                i++;
            }
            result+=j-i+1;
        }
        return result;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return atMax(nums,k)-atMax(nums,k-1);        
    }
};