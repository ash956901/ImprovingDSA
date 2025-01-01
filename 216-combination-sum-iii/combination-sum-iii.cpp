class Solution {
public:
    void solve(int number,int sum,int k,int n,vector<int> &temp,vector<vector<int>> &ans){
        if(temp.size()==k){
            if(sum==n){
                ans.push_back(temp);
            }
            return; 
        }
        if(temp.size()>k || sum>=n || number>9){
            return;
        }
        // cout<<"SUM:"<<sum<<endl;
        //take
        temp.push_back(number);
        solve(number+1,sum+number,k,n,temp,ans);
        temp.pop_back();
        //exclude 
         solve(number+1,sum,k,n,temp,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,0,k,n,temp,ans);
        return ans;
    }
};