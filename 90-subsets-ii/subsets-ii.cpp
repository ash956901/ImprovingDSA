class Solution {
public:
    void solve(vector<int> &nums,int i,vector<int> &temp,set<vector<int>>& ans){
        if(i>=nums.size()) return;

        for(int j=i;j<nums.size();j++){
            temp.push_back(nums[j]);
            ans.insert(temp);
            solve(nums,j+1,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        
        sort(nums.begin(),nums.end());

        solve(nums,0,temp,ans);

        vector<vector<int>> rtn;
        for(auto i:ans){
            rtn.push_back(i);
        }
        rtn.push_back({});
        return rtn;
    }
};