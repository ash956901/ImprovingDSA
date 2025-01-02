class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) { 
        int sum=0;
        vector<int> ps(words.size(),0);
        for(int i=0;i<words.size();i++){
            if(words[i][0]=='a' || words[i][0]=='e' || words[i][0]=='i' || words[i][0]=='o' || words[i][0]=='u'){
                int n=words[i].size()-1;
                if(words[i][n]=='a' || words[i][n]=='e' || words[i][n]=='i' || words[i][n]=='o' || words[i][n]=='u'){
                   sum+=1;
                }
            }
            ps[i]=sum;
        }

        for(auto i:ps) cout<<i<<" ";
        //get the ans vector
        vector<int> ans(queries.size(),0);
        for(int i=0;i<queries.size();i++){
            ans[i]=ps[queries[i][1]];
            if((queries[i][0]-1)>=0){
                ans[i]-=ps[queries[i][0]-1];
            }
        }

        return ans;
    }
};