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
    
    string preToInfix(string pre_exp) {
      stack<string> s;
      for(int i=pre_exp.size()-1;i>=0;i--){
          if(Operator(pre_exp[i])){
              //get two operands out of the back
              //concatenate and push them with the brackets in 
              string a=s.top();
              s.pop();
              string b=s.top();
              s.pop();
              string n="(" + a + pre_exp[i] +b +")";
              
              s.push(n);
              
          }
          else{
              //its an operand,push it into the stack
              s.push(string(1,pre_exp[i]));
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
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends