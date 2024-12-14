class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int i=0;
        map<int,int> freq;
        long long count=0;
        for(int j=0;j<nums.size();j++){
            freq[nums[j]]++;
            while((--freq.end())->first - freq.begin()->first > 2){
                freq[nums[i]]--;
                if(freq[nums[i]]==0) freq.erase(nums[i]);
                i++;
            }
            count+=j-i+1;
        }

        return count;
    }
};