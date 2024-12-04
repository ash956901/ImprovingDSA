class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0;
        int j=0;
        for(int i=0;i<str1.size();i++){
            char temp;
            if(str1[i]=='z') temp='a';
            else temp=str1[i]+1;
            cout<<"temp:"<<temp<<endl;
            if(temp==str2[j] || str1[i]==str2[j]){
                j++;
                if(j==str2.size()){
                    return true;
                }
            }

        }

        return false;
    }
};