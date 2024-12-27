//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void gbs(int num,string a,int l,bool one,vector<string> &ans){
        if(l==num){
            ans.push_back(a);
            return ;
        }
 
        
        //check if previous was not one 
        if(!one){
            gbs(num,a+"1",l+1,true,ans);
        }
        gbs(num,a+"0",l+1,false,ans);
    }
    vector<string> generateBinaryStrings(int num){
        vector<string> ans;
        gbs(num,"",0,false,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends