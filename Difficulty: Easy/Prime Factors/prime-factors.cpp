//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:

	vector<int>AllPrimeFactors(int N) {
	    vector<int> ans;
	    
	    int n=N;
	    
	    while(n%2==0){
	           n/=2;
	    }
	    if(n!=N) ans.push_back(2);
	    
	    for(int i=3;i*i<=n;i++){
	        int temp=n;
	        while(n%i==0){
	            n/=i;
	        }
	        
	        if(n!=temp) ans.push_back(i);
	    }
	    
	    if(n>2) ans.push_back(n);
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends