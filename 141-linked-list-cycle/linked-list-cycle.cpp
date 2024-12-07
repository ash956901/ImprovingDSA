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
        //making all INT_MIN,check if next of any is INT_MIN;
        ListNode* temp=head;
        while(temp->next!=NULL){
            if(temp->next->val==INT_MIN) return true;
            temp->val=INT_MIN;
            temp=temp->next;
        }


        return false;
    }
};