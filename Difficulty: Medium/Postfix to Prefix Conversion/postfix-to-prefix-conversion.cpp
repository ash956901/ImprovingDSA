//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
         bool Operator(char check){
            switch(check){
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                case '%':
                return true;
            }
            return false;
        }
  
    string postToPre(string post_exp) {
      stack<string> s;
      
      for(int i=0;i<post_exp.size();i++){
          if(Operator(post_exp[i])){
              //get two operands out of the back
              //concatenate and push them
              string a=s.top();
              s.pop();
              string b=s.top();
              s.pop();
              string n= post_exp[i]+ b+a   ;
              
              s.push(n);
              
          }
          else{
              //its an operand,push it into the stack
              s.push(string(1,post_exp[i]));
          }
      }
      
      //stack now has only the formed string we want , return it
      return s.top();
    }
  
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends