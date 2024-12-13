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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;

        int lengthA=1;
        int lengthB=1;

        while(tempA->next!=NULL){
            lengthA++;
            tempA=tempA->next;
        }

        while(tempB->next!=NULL){
            lengthB++;
            tempB=tempB->next;
        }

     

        //figure out the bigger list
        if(lengthB>=lengthA) {
            int diff=lengthB-lengthA;
            tempB=headB;
            tempA=headA;
            int cnt=0;
            //move b to a level
            while(cnt!=diff){
                tempB=tempB->next;
                cnt++;
            }
          
            // //now move until they become equal
            while(tempA!=tempB){
              
                tempB=tempB->next;
                tempA=tempA->next;
               
            }

            return tempB;

        }
        else{
            int diff=lengthA-lengthB;
            
            tempB=headB;
            tempA=headA;
            int cnt=0;
            //move a to a level
            while(cnt!=diff){
                tempA=tempA->next;
                cnt++;
            }
            

            // //now move until they become equal
            while(tempA!=tempB){
               
                tempB=tempB->next;
                tempA=tempA->next;
            }

            return tempA;
        }

        return tempA;
    }
};