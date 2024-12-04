class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int> freq;
            for(int j=i;j<s.size();j++){
                freq[s[j]]++;
                int least_freq=INT_MAX;
                int most_freq=0;

                for(auto it:freq){
                    least_freq=min(least_freq,it.second);
                      most_freq=max(most_freq,it.second);
                }

                sum+=(most_freq-least_freq);
            }
        }
        return sum;
    }
};