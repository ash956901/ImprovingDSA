class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int i=0;
        for(int j=0;j<s.size();j++){
            if(i<spaces.size() && j==spaces[i]){
                i++;
                
                ans.push_back(' ');
            }
                ans.push_back(s[j]);
            
        }

        return ans;
    }
};