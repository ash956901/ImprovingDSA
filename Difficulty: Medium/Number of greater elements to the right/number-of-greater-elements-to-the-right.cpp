//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
public:
    int solve(vector<int> &arr,int index){
        int count=0;
        
        for(int i=arr.size()-1;i>index;i--){
            if(arr[index]<arr[i]) count+=1;
        }
        
        return count;
    }
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
       
       vector<int> ans(indices.size(),0);
      
       
       for(int i=0;i<queries;i++){
           
           //find the count for each indices 
           int currIndex=indices[i];
           
           ans[i]=solve(arr,currIndex);
       }
       
       return ans;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> v1(n);
       for(int i = 0;i<n;i++) cin >> v1[i];
        int q; cin >> q;
        vector<int> v2(q);
        for(int i = 0;i<q;i++) cin >> v2[i];

        Solution obj;
        vector<int> ans = obj.count_NGE(n,v1,q,v2);

        for(int i = 0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends