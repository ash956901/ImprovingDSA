class Solution {
public:
    string removeOuterParentheses(string s) {
        bool start=false;
        int count=0;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(!start){
                if(s[i]=='(') {
                    start=true;
                   
                }
    
            }
            else{
                if(count==0 && s[i]==')'){
                    start=false;
                }
                else if(s[i]=='('){
                    ans.push_back('(');
                    count++;
                }
                else if(count!=0 && s[i]==')'){
                     ans.push_back(')');
                    count--;
                }
            }
        }
        return ans;
    }
};