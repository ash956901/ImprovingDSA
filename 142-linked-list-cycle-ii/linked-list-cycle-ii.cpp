/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return NULL;
        if(head->next==head) return head;
        //SLOW AND FAST POINTER
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(slow!=fast && slow->next!=NULL){
            slow=slow->next;
            if(fast->next) fast=fast->next;
            if(fast->next) fast=fast->next;

        }


        if(slow->next==NULL) return NULL;

        // fast=fast->next;
        // while(slow!=fast){
           
        //    slow=slow->next;
        //    fast=fast->next;
        //    fast=fast->next;
        // }

        fast=head;
        while(slow!=fast){
          
            slow=slow->next;
            if(slow==fast) return slow;
            fast=fast->next;
            cout<<"slow:"<<slow->val;
        }
     


        return slow;
    }
};