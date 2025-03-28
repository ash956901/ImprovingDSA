//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends

// Function to search a node in BST.
class Solution{

public:
    void inorder(Node* root,vector<int> &in){
    if(!root){
        return;
    }
    
    inorder(root->left,in);
    
    in.push_back(root->data);
    
    inorder(root->right,in);
}

    int floor(Node* root, int x) {
       if (root == NULL) return -1;
    
        vector<int> in;
        
        inorder(root,in);
        
        int ans=-1;
        
        bool flag=false;
        
        for(int i=0;i<in.size();i++){
                if(in[i]==x){
                    return x;
                }
                else if(in[i]>x){
                   if(i-1>=0) ans=in[i-1];
                   flag=true;
                   break;
                }
              
               
        }
        if(!flag){
            return in[in.size()-1];
        }
       
        return ans;
    }
};


//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends