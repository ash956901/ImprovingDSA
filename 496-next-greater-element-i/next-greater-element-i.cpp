class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> ind;
        vector<int> ng2(nums2.size(),-1);
        vector<int> ng1(nums1.size());
        stack<int> ng;
        //create mapping 
        for(int i=0;i<nums2.size();i++){
            ind[nums2[i]]=i;
        }

        //apply nge on nums2 and store it 
        for(int i=0;i<nums2.size();i++){
            
            while(!ng.empty() && nums2[ng.top()]<nums2[i]){
                int ngTop=ng.top();
                ng.pop();

                ng2[ngTop]=i;
            }

            ng.push(i);
        }

        //now traverse over nums 1 and for each element,get its position in nums2 and then use ng2 array to find the nge for it 
        for(int i=0;i<nums1.size();i++){
            //get the index of nums2
            int index=ind[nums1[i]];
            //get the nge from ng 2 and store in ng1
            ng1[i]=ng2[index]!=-1?(nums2[ng2[index]]):(-1);
        }


        return ng1;
    }
};