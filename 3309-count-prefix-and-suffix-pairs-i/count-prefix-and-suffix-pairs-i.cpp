class Solution {
public:
    bool isPrefixAndSuffix(string &a,string &b){
         if(b.size()<a.size()) return false;
        if(b.substr(0,a.size())==a&&b.substr(b.size()-a.size())==a) return true;
        return false;
    
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(isPrefixAndSuffix(words[i],words[j])) count++;
            }
        }

        return count ;
    }
};