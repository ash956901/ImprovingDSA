class Solution {
public:
    void solve(vector<int>& candidates,int i,int sum,int t,vector<vector<int>> &ans,vector<int> &temp){
        if(i>=candidates.size()){
            if(sum==t) ans.push_back(temp);
            return ;
        }

        if(sum==t){
            ans.push_back(temp);
            return;
        }
        if(sum>t){
            return ;
        }

        for(int ind=i;ind<candidates.size();ind++){
            temp.push_back(candidates[ind]);
            sum+=candidates[ind];
            solve(candidates,ind,sum,t,ans,temp);
            temp.pop_back();
            sum-=candidates[ind];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,0,0,target,ans,temp);
        return ans;
    }
};