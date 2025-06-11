class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for (char c : num) {
           
            while (k > 0 && !st.empty() && st.back() > c) {
                st.pop_back();
                --k;
            }
            st.push_back(c);
        }
      
        st.erase(st.size() - k, k);

       
        int i = 0;
        while (i < st.size() && st[i] == '0') ++i;
        st = st.substr(i);

        return st.empty() ? "0" : st;
    }
};
