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
    ListNode* sortList(ListNode* head) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        ListNode* temp=head;
        vector<int> c;
        while(temp->next!=NULL){
            c.push_back(temp->val);
            temp=temp->next;
        }
        c.push_back(temp->val);

        sort(c.begin(),c.end());
        temp=head;
        int i=0;
        while(temp->next!=NULL){
            temp->val=c[i];
            temp=temp->next;
            i++;
        }
          temp->val=c[i];
       return head;

    }
};