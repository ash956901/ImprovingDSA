class Solution {
public:
    bool isPalindrome(string &test){
        int i=0;
        int j=test.size()-1;
        while(i<j){
            if(test[i]!=test[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    void solve(string &s,int i,vector<vector<string>> &ans,vector<string> &temp){
        int n=s.size();
        if(i==n){
           
            ans.push_back(temp);
            return ;
        }

        //from the current index start forming partitions of diff sizes
        string t="";
        for(int j=i;j<n;j++){
            t+=s[j];
           
            if(isPalindrome(t)){
                temp.push_back(t);
                solve(s,j+1,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,0,ans,temp);
        return ans;
    }
};