class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> check;
        int size=0;
        for(char c:t){
            check[c]++;
            size++;
        }
        int minLength=INT_MAX;
        int minStart=0;
        int i=0;
        for(int j=0;j<s.size();j++){
            if(check[s[j]]>0){
                size--;
            }
             check[s[j]]--;
           
            while(size==0){
                if(j-i+1<minLength){
                    minLength=j-i+1;
                    minStart=i;
                }
                char d=s[i++];
                 if(++check[d]>0)size++;
               
            }


        }

        return minLength==INT_MAX?(""):(s.substr(minStart,minLength));
    }
};