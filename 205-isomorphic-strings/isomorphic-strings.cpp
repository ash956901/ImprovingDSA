class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> v(200,-1);
        vector<int> w(200,-1);

        if(s.size() != t.size()) return false;
        
        for(int i =0;i<s.size();i++){
            v[s[i]] = t[i];
            w[t[i]] = s[i];
        }

        for(int i =0;i<s.size();i++)
        {
            char temp = s[i];
            s[i] = (char)v[s[i]];
            // cout<<temp<<" "<<s[i]<<endl;
            if(w[s[i]] != temp) return false;
        }

        if(s == t) return true;
        return false;
    }
};