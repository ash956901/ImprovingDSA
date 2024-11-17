class Solution {
public:
    unordered_map<char,int> freq;   

    string frequencySort(string s) {
       for(int i=0;i<s.size();i++){
            freq[s[i]]++;
       }

      sort(s.begin(),s.end(),[&](char a,char b){
        if(freq[a]!=freq[b]){
             return freq[a]>freq[b];
        }
        return (int)a>(int)b;
      });


      return s;

    }
};