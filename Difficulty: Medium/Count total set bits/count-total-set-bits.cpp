//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
  
    int countSetBits(int n)
    {
       //include 0
       n=n+1;
       int result=0;
       for(int bit=0;bit<30;bit++){
           int groupSize=1<<(bit+1);
           
           int fullGroups=n/groupSize;
           int fullGroupsBits=fullGroups*(groupSize/2);
           //since half are 0's and half are 1's
           
           int remainingNumbers=n%groupSize;
           int remainingBits=max(0,remainingNumbers-(groupSize/2));
           
           result+=fullGroupsBits+remainingBits;
           
           
           
       }
     
       return result;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  
cout << "~" << "\n";
}
	  return 0;
}

// } Driver Code Ends