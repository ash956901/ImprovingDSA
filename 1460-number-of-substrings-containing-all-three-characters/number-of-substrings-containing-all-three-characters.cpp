class Solution {
public:
    int solve(string s,int k){
        unordered_map<char,int> freq;
        int i=0;
        int dist=0;
        int res=0;
        for(int j=0;j<s.size();j++){
            freq[s[j]]++;
            if(freq[s[j]]==1) dist++;
            while(dist>k){
                freq[s[i]]--;
                if(freq[s[i]]==0) dist--;
                i++;
            }
            res+=(j-i+1);
            
        }

        return res;
    }
    int numberOfSubstrings(string s) {
        return solve(s,3)-solve(s,2);
    }
};