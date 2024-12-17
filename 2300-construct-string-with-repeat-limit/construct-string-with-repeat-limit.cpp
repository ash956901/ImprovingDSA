class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }

        char prevBig='\0';
        string ans="";
        int i=25;
        while(i>=0){
            if(prevBig=='\0' && freq[i]!=0){
                for(int j=0;j<repeatLimit && freq[i]!=0;j++){
                    freq[i]--;
                    ans+=char('a'+i);
                }
                if(freq[i]!=0) prevBig='a'+i;

                i--;
            }
            else if(freq[i]!=0){
                ans+=char('a'+i);
                freq[i]--;
                for(int j=0;j<repeatLimit && freq[prevBig-'a']!=0;j++){
                    freq[prevBig-'a']--;
                    ans+=prevBig;
                }
                if(freq[prevBig-'a']==0) prevBig='\0';
                if(freq[i]==0) i--;
            }
            else{
                i--;
            }
        }

        return ans;
    }
};