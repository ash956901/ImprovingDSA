class Solution {
public:
    void solve(vector<int>& candidates,int i,int sum,int t,vector<vector<int>> &ans,vector<int> &temp){
        if(i>=candidates.size()){
            if(sum==t){
                ans.push_back(temp);
                return; 
            }
            return ;
        }

         if(sum>t){
            return; 
        }

        if(sum==t){
            ans.push_back(temp);
            return;
        }

       

        //take
        temp.push_back(candidates[i]);
        solve(candidates,i+1,sum+candidates[i],t,ans,temp);
        temp.pop_back();

        //loop till you find the index with diff element thanthe current one 
        int element=candidates[i];
        int j=i+1;
        while(j<candidates.size() && candidates[j]==candidates[i]){
            
            j++;
         
        }
        //untake
        solve(candidates,j,sum,t,ans,temp);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,0,target,ans,temp);
        return ans;
    }
};


