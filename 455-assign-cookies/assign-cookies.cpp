class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      if(s.empty()) return 0;
      sort(g.begin(),g.end());
      sort(s.begin(),s.end());
      int i=s.size()-1;
      int j=g.size()-1;
      int count=0;
      while(j>=0 && i>=0 ){
        if(g[j]<=s[i]){
            count++;
            j--;
            i--;
        }
        else{
            j--;
        }
       
      }

      return count;
    }
};