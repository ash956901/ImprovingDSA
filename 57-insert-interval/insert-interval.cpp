class Solution {
public:
    vector<vector<int>> solve(vector<vector<int>> &arr){
        vector<vector<int>> newArr;
        newArr.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            auto &last=newArr.back();
            auto &curr=arr[i];

            if(curr[0]<=last[1]){
                last[1]=max(last[1],curr[1]);
            }
            else{
                newArr.push_back(curr);
            }

        }

        return newArr;

        
    }
    vector<vector<int>> insert(vector<vector<int>>& 
    intervals, vector<int>& newInterval) {
        int i=0;
        for(;i<intervals.size();i++){
              if(newInterval[0]<intervals[i][0]){
                break;
            }
            if(newInterval[0]<=intervals[i][1]){
                i++;
                break;
            }
           
        }
     
        vector<vector<int>> ans;
        for(int j=0;j<i;j++){
            ans.push_back(intervals[j]);
        }
        ans.push_back(newInterval);
        for(int j=i;j<intervals.size();j++){
            ans.push_back(intervals[j]);
        }
        
        ans=solve(ans);
        return ans;
    }
};