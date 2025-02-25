//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string& s) {
       string ans;
       stack<char> check; 
       unordered_map<char,int> priority;
       priority.insert({'^',3});
       priority.insert({'/',2});
       priority.insert({'*',2});
       priority.insert({'+',1});
       priority.insert({'-',1});
       priority.insert({'(',0});
       priority.insert({')',0});
       
       for(int i=0;i<s.size();i++){
           //check if its a char
           if(!priority.count(s[i])){
               //push it to the ans string
    
               ans.push_back(s[i]);
           }
           else{
               //its one of the operators
               //check if its ) then pop till we reach (
               if(s[i]==')'){
                   while(check.top()!='('){
                       ans.push_back(check.top());
                       check.pop();
                   }
                   //pop the (
                   check.pop();
               }
               //otherwise its one of the operators or (
               else if(s[i]=='('){
                   check.push('(');
               }
               else{
                        //its one of the operators
                   while(!check.empty() && check.top()!='(' && priority[s[i]]<=priority[check.top()]){
                       ans.push_back(check.top());
                       check.pop();
                   }
                   
                   check.push(s[i]);
                   
               }
               
              
               
           }
           
           
       } 
       
       //now push all the remaining chars to the ans
       while(!check.empty()){
           ans.push_back(check.top());
           check.pop();
       }
       
       return ans;
    }
};


//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends