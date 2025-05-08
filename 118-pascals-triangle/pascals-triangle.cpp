class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows==1) return ans;
        ans.push_back({1,1});
        if(numRows==2) return ans;
        for(int i=2;i<numRows;i++){
            int j=0;
            vector<int> temp;
            for(int j=0;j<=i;j++){
                int ele=0;
                if(i-1>=0 && j-1>=0) ele+=ans[i-1][j-1];
                if(i-1>=0 && j<ans[i-1].size()) ele+=ans[i-1][j];
                temp.push_back(ele);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};