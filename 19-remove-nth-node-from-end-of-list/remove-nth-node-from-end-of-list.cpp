/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL) return NULL;
      
        //get the length
        ListNode* temp=head;
        int count=1;
        while(temp->next!=NULL){
            temp=temp->next;
            count++;
        }

        //caluclate the delete Posn from the start
        int deletePosn=count-n+1;
        

        //get that node
        ListNode* prev=NULL;
        temp=head;
        count=1;
        while(count!=deletePosn){
            prev=temp;
            temp=temp->next;
            count++;
        }

        if(temp->next==NULL){
            //tail Node
            prev->next=NULL;
        }
        else if(prev==NULL){
            head=temp->next;
            temp->next=NULL;
        }
        else{
            //middle Node
            prev->next=temp->next;
            temp->next=NULL;
        }

        return head;
    }
};