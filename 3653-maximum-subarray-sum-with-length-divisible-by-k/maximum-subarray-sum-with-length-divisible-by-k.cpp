class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans=LLONG_MIN;
        vector<long long> prefix(nums.size(),0);
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            prefix[i]=sum;
        }



        for(int i=0;i<k;i++){
            long long subArraySum=0;
            long long maxi=LLONG_MIN;
            for(int j=i+k-1;j<nums.size();j+=k){
                subArraySum+=prefix[j];
                if(j-k>=0){
                    subArraySum-=prefix[j-k];
                }


                maxi=max(maxi,subArraySum);

                if(subArraySum<0) subArraySum=0;
            }

             ans=max(ans,maxi);

        }


        return ans;

       

    }
};