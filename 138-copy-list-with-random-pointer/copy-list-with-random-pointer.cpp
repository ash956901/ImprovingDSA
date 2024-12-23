/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        Node* temp=head->next;
        Node* copyHead=new Node(head->val);
        Node* temp1=copyHead;
        //copy the list
        while(temp!=NULL){
            Node* Put=new Node(temp->val);
            temp1->next=Put;
            temp1=temp1->next;
            temp=temp->next;
        }

        Node* copyPointer=copyHead;
        Node* track=head;
        Node* restore=head;
        Node* copyTrack=copyHead;
        int count=1;
        //assign random
        while(head!=NULL){
            while(track!=head->random){
                count++;
                track=track->next;
            }
            int i=1;
            while(i<count){
                copyPointer=copyPointer->next;
                i++;
            }
            copyTrack->random=copyPointer;
            copyTrack=copyTrack->next;
            copyPointer=copyHead;
            track=restore;
            count=1;
            head=head->next;
        }
        return copyHead;
    }
    
};