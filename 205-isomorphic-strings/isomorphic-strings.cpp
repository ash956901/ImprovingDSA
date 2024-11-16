class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> check;
        unordered_map<char, char> m;
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); i++) {
            if (check.count(s[i])) {
                // get the char
                char c = check[s[i]];
                // check if equal to the current char in string t
                // if not early return
                if (c != t[i])
                    return false;

                // else replace
                s[i] = c;
            } else {
                if (!m.count(t[i]) || m[t[i]] == s[i]) {
                    // create a mapping of the current char of s to t
                    check[s[i]] = t[i];
                    //create a reverse mapping to check for the same map condn
                    m[t[i]]=s[i];
                    // replace t
                    s[i] = t[i];
                } else {
                    return false;
                }
            }
        }
        cout << "S:" << s << endl;
        cout << "T:" << t << endl;
        return s == t;
    }
};