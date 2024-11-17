class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxi=INT_MIN;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')') count++;
            else if(s[i]=='(') count--;
            maxi=max(maxi,count);
        }

        return maxi;
    }
};