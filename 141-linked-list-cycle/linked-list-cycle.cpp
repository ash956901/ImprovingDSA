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
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        if(head->next==NULL) return false;
        if(head->next==head) return true;
        //SLOW AND FAST POINTER
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(slow!=fast && slow->next!=NULL){
            slow=slow->next;
            if(fast->next) fast=fast->next;
            if(fast->next) fast=fast->next;

        }


        if(slow->next==NULL) return false;
        return true;
}
     
};