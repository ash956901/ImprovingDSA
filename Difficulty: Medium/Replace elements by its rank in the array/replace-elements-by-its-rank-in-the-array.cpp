//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        unordered_map<int,int> check;
        vector<int> temp(arr);
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            if(check.find(temp[i])==check.end()){
                if(i-1>=0 && check.find(temp[i-1])!=check.end()){
                     check[temp[i]]=check[temp[i-1]]+1;
                }
                else{
                    check[temp[i]]=i+1;
                }
            }
        }
        
        for(int i=0;i<arr.size();i++){
            arr[i]=check[arr[i]];
        }
        return arr;
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
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends