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
  ListNode* reverseList(ListNode* head, int k) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;

    ListNode* prev = NULL;
    ListNode* curr = head;
    int cnt = 1;
    while (cnt != k) {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        cnt++;
    }
    curr->next = prev;

    return curr;
}
    ListNode* solve(ListNode* head,int k,int cnt){
        if(cnt<k){
            return head;
        }
       
        ListNode* lastNode=head;
        ListNode* nextNode=head;
        int length=0;
        while(length!=k){
            nextNode=nextNode->next;
            length++;
        }
      
        ListNode* reversedHead=reverseList(head,k);
        lastNode->next=solve(nextNode,k,cnt-k);
        
        return reversedHead;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        int cnt=1;
        while(temp->next!=NULL){
            cnt++;
            temp=temp->next;
        }
 
        return solve(head,k,cnt);
    }
};