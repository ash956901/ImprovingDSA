class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int i=0;
        int res=0;
        for(int j=0;j<s.size();j++){
            freq[s[j]]++;
            while(freq[s[j]]>1){
                freq[s[i++]]--;
            }
            res=max(res,j-i+1);
        }   
        return res;
    }
};