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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;

        ListNode* prevOdd=head;
        ListNode* prevEven=head->next;
        ListNode* evenBegin=prevEven;


        int count=3;
        ListNode* curr=head->next->next;
        if(curr==NULL) return head;
        while(curr->next!=NULL){
            if(count & 1) {
                prevOdd->next=curr;
                prevOdd=curr;
            }
            else{
                prevEven->next=curr;
                prevEven=curr;
            }
            count++;
            curr=curr->next;
        }
    
         if(count & 1) {
                prevOdd->next=curr;
                prevOdd=curr;
                prevEven->next=NULL;
            }
            else{
                prevEven->next=curr;
                prevEven=curr;
                 
            }
        prevOdd->next=evenBegin;


        return head;
       
    }
};