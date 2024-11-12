class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix[0].size();
        int l=0;
        int r=matrix.size()*matrix[0].size()-1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;

            int row=mid/n;
            int col=mid%n;
            int curr_value=matrix[row][col];
            if(curr_value==target){
                ans=mid;
                break;
            }
            else if(curr_value>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }


        if(ans>=0) return true;
        return false;
    }
};