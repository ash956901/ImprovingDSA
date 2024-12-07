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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=head;
        while(fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next;
            if(fast->next) fast=fast->next;
        }

        prev->next=slow->next;
        slow->next=NULL;
        return head;
        
    }
};