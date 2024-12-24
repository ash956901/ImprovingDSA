class Solution {
public:
    int solve(string s,int i,int sign,long long res){
        if(i>=s.size() || !isdigit(s[i])) return res*sign;

        res=(res*10)+s[i]-'0';
        
        if(res*sign<=INT_MIN) return INT_MIN;
        if(res*sign>=INT_MAX) return INT_MAX;

        return solve(s,i+1,sign,res);
    }
    int myAtoi(string s) {
        int i=0;            
        for(;s[i]==' ';i++);
        if(i==s.size()) return 0;
        string j=s.substr(i);
        if(j.empty()) return 0;
        int index=0; 
        int sign=1;
        if(s[i]=='+'){
            index=1;
            sign=1;
        }
        else if(s[i]=='-'){
            index=1;
            sign=-1;
        }

        return solve(j,index,sign,0);
    }
};