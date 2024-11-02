class Solution {
public:
    bool solve(vector<int> &nums,float div,int t){
        int result=0;
        for(int i=0;i<nums.size();i++){
            float q=float(nums[i])/div;
            result+=ceil(q);
        }
       
        return result<=t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int mid=l+(r-l)/2;
        while(l<r){
            if(solve(nums,mid,threshold)){
                r=mid;
            }
            else{
                l=mid+1;
            }
            mid=l+(r-l)/2;
        }

        return l;
    }
};