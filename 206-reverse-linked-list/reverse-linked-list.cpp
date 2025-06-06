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
    ListNode* solve(ListNode* head){
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* r=solve(head->next);
        head->next->next=head;
        head->next=prev;

        return r;
        
    }
    ListNode* reverseList(ListNode* head) {
        return solve(head);

    }
};