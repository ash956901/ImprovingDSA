class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind=0;
        int i=0;
        int n=nums.size();
        while(i<n){
            if(i>maxind) return false;
            maxind=max(maxind,nums[i]+i);
            i++;
        }
        return true;
    }
};