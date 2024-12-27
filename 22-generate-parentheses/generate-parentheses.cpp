class Solution {
public:
    void backtrack(int open,int closed,int n,string &ans,vector<string> &res){
        if(ans.length()==2*n){
            res.push_back(ans);
            return;
        }

        if(open<n){
            ans.push_back('(');
            open+=1;
            backtrack(open,closed,n,ans,res);
            open-=1;
            ans.pop_back();
        }

        if(closed<n && open>closed){
            ans.push_back(')');
            closed+=1;
            backtrack(open,closed,n,ans,res);
            closed-=1;
            ans.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string ans="";
        backtrack(0,0,n,ans,res);
        return res;
    }
};