class Solution {
public:
    bool isValid(string s) {
        int n=s.size()-1;
        stack<char> check;
        for(int i=n;i>=0;i--){
            if(s[i]==')' || s[i]=='}' || s[i]==']'){
                check.push(s[i]);
                continue;
            }
            if(!check.empty() && s[i]=='('){
                if(check.top()==')'){
                    check.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
            if(!check.empty() && s[i]=='['){
                if(!check.empty() && check.top()==']'){
                    check.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
            if(!check.empty() && s[i]=='{'){
                if(!check.empty() && check.top()=='}'){
                    check.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }

        if(check.empty()){
            return true;
        }

        return false;

    }
};