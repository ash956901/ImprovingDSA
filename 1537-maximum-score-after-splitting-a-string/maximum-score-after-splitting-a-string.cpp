class Solution {
public:
    int maxScore(string s) {
        vector<int> backCheck(s.size(),0);
        int sum=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                sum+=1;
            }
            backCheck[i]=sum;
        }


        sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0'){
                sum+=1;
            }
            int temp=sum;
            if(i+1<s.size()){
                temp+=backCheck[i+1];
            }
            if(temp>maxi)maxi=temp;
        }

        return maxi;
    }
};