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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;

        ListNode* dummy=new ListNode(0);

        dummy->next=head;

        ListNode* kth=head;

        int count=1;

        //take out length and mod k
        int length=1;
        ListNode* lengthNode=head;
        while(lengthNode->next!=NULL) {lengthNode=lengthNode->next; length++;}
        k=k%length;
        if(k==0) return head;
        while(count!=k){
            count++;
            kth=kth->next;
        }

        ListNode* rt=dummy;

        while(kth->next!=NULL){
            dummy=dummy->next;
            kth=kth->next;
        }

        //define new head
        ListNode* rNode=dummy->next;
        dummy->next=NULL;
        kth->next=head;

        rt->next=NULL;
      
       
        return rNode;
    }
};