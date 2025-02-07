//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
       vector<long long int> ans;
       long long int res=Arr[0];
       for(int i=1;i<N;i++){
           res^=Arr[i];
       }
       
       long long int rmSb=res&~(res-1);
       
       long long int a=0;
       long long int b=0;
       for(int i=0;i<N;i++){
           if(Arr[i]&rmSb){
               a^=Arr[i];
           }
           else{
               b^=Arr[i];
           }
       }
       
       if(a>b){
           ans.push_back(a);
           ans.push_back(b);
           return ans;
       }
       
       ans.push_back(b);
       ans.push_back(a);
       return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends