//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends

//User function Template for C++


class Solution
{
    public:
    struct Node{
        
            int index;
            int nodeIndex;
            int val;

            Node(int i,int ni,int val){
                this->index=i;
                this->nodeIndex=ni;
                this->val=val;
            }
    };

    struct cNode{
        bool operator()(const Node &a,const Node &b)const{
            return a.val>b.val;
        }
    };
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
    
        priority_queue<Node,vector<Node>,cNode> pq;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            if(!arr[i].empty()){
                pq.push(Node(i,0,arr[i][0]));
            }
        }
       
        while(!pq.empty()){
            Node topNode=pq.top();
            pq.pop();
            
           ans.push_back(topNode.val);
            
            
            //check if more ahead
            if(topNode.nodeIndex<arr[topNode.index].size()-1){
                pq.push(Node(topNode.index,topNode.nodeIndex+1,arr[topNode.index][topNode.nodeIndex+1]));
            }

        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}






// } Driver Code Ends