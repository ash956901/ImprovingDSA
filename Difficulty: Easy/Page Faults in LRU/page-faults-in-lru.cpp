//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Node{
    public:
      int key;
      Node* prev;
      Node* next;
      
      Node(int k){
          this->key=k;
          this->prev=nullptr;
          this->next=nullptr;
      }
};

class Solution{
public:
    unordered_map<int,Node*> check;
    Node* head=nullptr;
    Node* tail=nullptr;
    int capacity=0;
    void addToTail(Node* node){
        node->prev=tail;
        node->next=nullptr;
        if(tail){
            tail->next=node;
        }
        tail=node;
        if(!head){
            head=node;
        }
    }
    
    void removeNode(Node* node){
        if(node->prev){
            node->prev->next=node->next;
        }
        else{
            head=node->next;
        }
        
        if(node->next){
            node->next->prev=node->prev;
        }
        else{
            tail=node->prev;
        }
       
        
    }
    
    void moveToTail(Node* node){
        removeNode(node);
        addToTail(node);
    }
    
    int pageFaults(int N, int C, int pages[]){
        int pf=0;
        for(int i=0;i<N;i++){
            if(check.find(pages[i])!=check.end()){
                    moveToTail(check[pages[i]]);
                    continue;
               }
           if(capacity<C ){
               pf++;
               Node* temp=new Node(pages[i]);
               addToTail(temp);
               check[pages[i]]=temp;
               capacity++;
           }
           else{
               //capacity full
               //its there
               if(check.find(pages[i])!=check.end()){
                    moveToTail(check[pages[i]]);
               }
               //its not there
               else{
                   //delete the lru one
                   int temp=head->key;
                   removeNode(head);
                   check.erase(temp);
                   //add the one required at the end
                   Node* newNode=new Node(pages[i]);
                   addToTail(newNode);
                   check[pages[i]]=newNode;
                   
                   //increase the pf 
                   pf++;
               }
           }
        }
        return pf;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends