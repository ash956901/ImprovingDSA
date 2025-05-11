class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if(num.empty()) return ans;
        dfs(num,target,0,0,0,"",ans);
        return ans;
    }
private:
    void dfs(string &num,long long target,int posn,long long eval,long long multed,string path,vector<string>&ans){
        int n=num.size();
        if(posn==n){
            if(eval==target){
                ans.push_back(path);
                return;
            }
            return;
        }

        for(int i=posn;i<n;i++){
            
            if(i>posn && num[posn]=='0') break;
            long long curr=stoll(num.substr(posn,i-posn+1));
            string currstr=num.substr(posn,i-posn+1);

            if(posn==0){
                dfs(num,target,i+1,curr,curr,currstr,ans);
            }
            else{
                //Addition
                dfs(num,target,i+1,eval+curr,curr,path + "+" + currstr,ans);
                //Subtraction
                dfs(num,target,i+1,eval-curr,-curr,path + "-" + currstr,ans);
                //Multiplication
                dfs(num,target,i+1,eval-multed+multed*curr,multed*curr,path + "*" + currstr,ans);

            }

        }
    }
};