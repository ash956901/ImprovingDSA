class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> freq;
        int i=0;
        int res=0;
        for(int j=0;j<s.size();j++){
            freq[s[j]]++;
            while(freq['a']>0 && freq['b']>0 && freq['c']>0){
                res+=(s.length()-j);
                freq[s[i++]]--;
            }
          
        }
        return res;
    }
};