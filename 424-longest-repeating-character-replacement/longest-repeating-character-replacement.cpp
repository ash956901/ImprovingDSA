class Solution {
public:
    int characterReplacement(string s, int k) {
       if(s.length()==0) return 0;
       if(s.length()<=k) return s.length();

       int maxi=0;
       unordered_map<char,int> check;
       int i=0;
       int res=0;
       for(int j=0;j<s.size();j++){
            check[s[j]]++;
            maxi=max(maxi,check[s[j]]);
            while(j-i+1-k>maxi){
                check[s[i]]--;
                i++;
            }
            res=max(res,j-i+1);
       } 

       return res;

    }
};