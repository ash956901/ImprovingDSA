class Solution {
public:
    void reverseStr(string &s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    bool rotateString(string s, string goal) {
        bool ans=false;
        string temp=s;
        int n=s.size()-1;
        while(true){
            //reverse one time
            reverseStr(s);
            //get the last char and pop it 
            char last=s[n];
            s.pop_back();
            //now reverse the string again
            reverseStr(s);
            //push back the char now 
            s.push_back(last);

            if(s==goal){
                ans=true;
                break;
            }
            if(s==temp){
                break;
            }
        }
        
        return ans;
    }
};