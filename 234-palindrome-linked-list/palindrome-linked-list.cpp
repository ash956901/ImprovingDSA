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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        vector<int> check;
        while(temp->next!=NULL) {
            check.push_back(temp->val);
            temp=temp->next;
            }
        check.push_back(temp->val);

       
        int i=0;
        int j=check.size()-1;
        while(i<j){
            if(check[i]==check[j]) {
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        
        return true;
      
    }
};