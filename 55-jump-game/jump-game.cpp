class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int i=0;
        while(i<nums.size()){
            int curr=nums[i];
            if(curr==0) return false;
            if(i+curr>=nums.size()-1) return true;
            //find the max within that range
            int maxi=INT_MIN;
            int mi=i+1;
            for(int j=i+1;j<=i+curr;j++){
                if(j+nums[j]>maxi){
                    maxi=j+nums[j];
                    mi=j;
                }
            }

            i=mi;


        }
        return false;
    }
};