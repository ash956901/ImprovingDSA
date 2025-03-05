class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nge(nums.size(),-1);
        stack<int> ng;

        //run one time for the normal case ,and one time more to wrap around  
        //for circular case 

        for(int j=0;j<2;j++){
            for(int i=0;i<nums.size();i++){
                while(!ng.empty()&&nums[ng.top()]<nums[i]){
                    int ngTop=ng.top();

                    ng.pop();
                    nge[ngTop]=nums[i];
                }

                ng.push(i);
            }
        }

      

        return nge;
    }
};