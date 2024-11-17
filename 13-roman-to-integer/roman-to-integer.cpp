class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> val;

        val.insert({'I', 1});
        val.insert({'V', 5});
        val.insert({'X', 10});
        val.insert({'L', 50});
        val.insert({'C', 100});
        val.insert({'D', 500});
        val.insert({'M', 1000});

        int count = 0;
        int i = 0;
        while (i < s.size()) {

            if (s[i] == 'I' && i + 1 < s.size()) {
                if (s[i + 1] == 'V') {
                    count += 4;
                    i += 2;
                } else if (s[i + 1] == 'X') {
                    count += 9;
                    i += 2;
                } else {
                    count += 1;
                    i++;
                }
            }
            else if (s[i] == 'X' && i + 1 < s.size()) {
                if (s[i + 1] == 'L') {
                    count += 40;
                    i += 2;
                } else if (s[i + 1] == 'C') {
                    count += 90;
                    i += 2;
                } else {
                    count += 10;
                    i++;
                }
            }
            else if (s[i] == 'C' && i + 1 < s.size()) {
                if (s[i + 1] == 'D') {
                    count += 400;
                    i += 2;
                } else if (s[i + 1] == 'M') {
                    count += 900;
                    i += 2;
                } else {
                    count += 100;
                    i++;
                }
            }

            else{
                count+=val[s[i]];
                i++;
            }
        }

        return count;
    }
};