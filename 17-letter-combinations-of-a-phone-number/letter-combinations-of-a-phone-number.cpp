class Solution {
public:
    void solve(string &digits,int i,string &temp,vector<string> &ans,unordered_map<int,int> &mp){
        if(i>=digits.size()){
            ans.push_back(temp);
            return;
        }

        int num=digits[i]-'0';
        int start=mp[num];
        int end=start+3;
        if(num==7 || num==9){
            end+=1;
        }

        while(start<end){
            temp.push_back((char)start);
            solve(digits,i+1,temp,ans,mp);
            temp.pop_back();
                  start++;
        }

    }
    vector<string> letterCombinations(string digits) {
        int n=2;
        int sn=97;
        unordered_map<int,int> mp;
        vector<string> ans;
        if(digits.empty()) return ans;
        while(n<=9){
            mp[n]=sn;
            if(n==7){
                sn+=4;
            }
            else{
                  sn+=3;
            }
            n++;
          
        }
        string temp="";
        solve(digits,0,temp,ans,mp);
        return ans;
    }
};