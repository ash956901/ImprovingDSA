class Solution {
public:
    int jump(vector<int>& nums) {
        int steps=0;
        int i=0;
        while(i<nums.size()){
            if(i==nums.size()-1) break;
            int curr=nums[i];
            int maxReachable=INT_MIN;
            int ind=i+1;
            for(int j=i+1;j<=i+curr;j++){
                if(j==nums.size()-1){
                    ind=j;
                    break;
                }
                int temp=maxReachable;
                maxReachable=max(maxReachable,j+nums[j]);
                if(temp!=maxReachable) ind=j;
            }
            steps++;
            i=ind;
        }   
        return steps;

    }
};