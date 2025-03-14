class Solution {
public:
    string expandFromCenter(string &s,int left,int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }

        return s.substr(left+1,right-left-1);
    }
    string longestPalindrome(string s) {
        if(s.length()<=1) return s;
        string max_str="";


        for(int i=0;i<s.size();i++){
            string odd=expandFromCenter(s,i,i);
            string even=expandFromCenter(s,i,i+1);

            if(odd.length()>max_str.length()){
                max_str=odd;
            }
            if(even.length()>max_str.length()){
                max_str=even;
            }
        }

        return max_str;
    }
};