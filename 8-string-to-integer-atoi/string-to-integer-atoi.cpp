class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long long num = 0;
        int i = 0;
        bool neg = false;
        for (; s[i] == ' '; i++)
            ;
        int count = 0;
        for (; s[i] == '+' || s[i] == '-'; i++) {
            count += 1;
            if (s[i] == '-')
                neg = true;
        }
        if (count > 1)
            return 0;
        long long mul = 10;
        for (; s[i] == '0'; i++)
            ;
        bool greaterInt=false;
        for (; i < n; i++) {

            if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' ||
                s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' ||
                s[i] == '8' || s[i] == '9') {
                num = (num * mul);
                num += (s[i] - '0');

            } else {
                break;
            }

            if (num > INT_MAX) {
                num = INT_MAX;
                greaterInt=true;
                break;
            }
        }
        if (neg) {
                if(num==INT_MAX && greaterInt){
                    num=INT_MIN;
                    
                }
                else{
                num -= (2 * num);
                if (num < INT_MIN) {
                    num = INT_MIN;
                }
                }
        }
        return num;
    }
};