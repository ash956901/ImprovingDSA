class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int firstIndex=0;
        for(firstIndex=0;s[firstIndex]==' ';firstIndex++);

        int i=s.size()-1;
        while(s[i]==' '){
            i--;
        }
        int j=i;

        while(i>=firstIndex && j>=firstIndex){

            //get i to space
            while(i>=0 && s[i]!=' '){
                i--;
            }

            //store i
            int temp=i;

             i=i+1;
            while(i<=j){
                ans.push_back(s[i]);
                i++;
            }

           

            //restore the indexes both to the temp
            i=temp;
          
             ans.push_back(' ');
            //now move to the next char for iteration 
            while( i>=firstIndex && s[i]==' '){
                i--;
            }
            j=i;
            cout<<"ANS:"<<ans<<endl;
            cout<<"i and j:"<<i<<" "<<j<<endl;

        }
        ans.pop_back();
        return ans;
    }
};