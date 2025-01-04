class Solution {
public:
    int countPalindromicSubsequence(string s) {
       unordered_map<char,pair<int,int>> mp;
       for(int i=0;i<s.size();i++){
            if(mp.count(s[i])){
                mp[s[i]].second=i;
            }
            else{
                mp[s[i]].first=i;
            }
       }

       int count=0;
       vector<int> visited(26,0);
       for(auto i:mp){
        int firstIndex=i.second.first;
        int secondIndex=i.second.second;

        int unique=0;
        for(int j=firstIndex+1;j<secondIndex;j++){
            if(!visited[(int)s[j]-'a']) {unique+=1;
                visited[(int)s[j]-'a']=1;
            }
        }
        visited.assign(26,0);
        count+=unique;
        unique=0;
       }


       return count;
    }
};