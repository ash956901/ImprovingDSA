class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int> netScore(values.size(),0);
        int maxi=INT_MIN;
        for(int i=values.size()-1;i>=0;i--){
            int temp=values[i]-i;
            maxi=max(maxi,temp);
            netScore[i]=maxi;
        }

        for(auto i:netScore) cout<<i<<" ";
        cout<<endl;
        int ans=INT_MIN;
        for(int i=0;i<values.size()-1;i++){
            
            ans=max(ans,values[i]+ i+netScore[i+1]);    
         }

        return ans;
    }
};