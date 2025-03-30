//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    struct node{
        int w;
        int v;
        
        node(int w,int v){
            this->w=w;
            this->v=v;
        }
    };
    
    struct cNode{
        bool operator()(const node &a,const node &b)const{
          double r1 = (a.w == 0) ? 0 : (double)a.v / a.w;
        double r2 = (b.w == 0) ? 0 : (double)b.v / b.w;
        return r1 < r2; 
            if(a.v/a.w==b.v/b.w){
                return a.w<b.w;
            }
        }
    };
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
       priority_queue<node,vector<node>,cNode> pq;
       double ans=0;
       int i=0;
       while(i<val.size()){
           pq.push(node(wt[i],val[i]));
           i++;
       }
       
       
     while(!pq.empty()){
          node curr=pq.top();
          pq.pop();
          
          
          if(curr.w<=capacity){
              ans+=curr.v;
              capacity-=curr.w;
          }
          else{
              ans+=((double)curr.v/curr.w)*capacity;
              capacity=0;
              break;
          }
       }
       return ans;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends