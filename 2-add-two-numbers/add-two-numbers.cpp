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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;

        int carry=0;
        while(temp1->next!=NULL && temp2->next!=NULL){
            int val1=temp1->val;
            int val2=temp2->val;
            int sum=val1+val2;
            if(carry) sum+=1;
            if(sum>=10){
                temp1->val=sum%10;
                carry=1;

            }
            else{
                carry=0;
                temp1->val=sum;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }


        // //add last two in loop
        int sum=temp1->val+temp2->val;
      
        if(carry) sum+=1;
            if(sum>=10){
                cout<<"SUM:"<<sum<<endl;
                temp1->val=sum%10;
                
                carry=1;

            }
            else{
                carry=0;
                temp1->val=sum;
            }
        
        if(temp1->next==NULL && temp2->next==NULL){
            if(carry){
                 temp1->next=new ListNode(1);
            }
           
            return l1;
        }
        
        // //check whihc one was null
        if(temp1->next==NULL){
            temp1->next=(temp2->next);
            if(temp2->next!=NULL) temp1=temp1->next;
            
        }
        else{
            temp1=temp1->next;
        }

        while(temp1->next!=NULL && carry!=0){
            int val=temp1->val+carry;
            if(val>=10){
                carry=1;
                temp1->val=val%10;
            } 
            else{
                carry=0;
                temp1->val=val;
            } 
            
            temp1=temp1->next;
        }

        if(carry) {
            if(temp1->val+1>=10){
                 temp1->val=0;
            temp1->next=new ListNode(1);
            }
            else{
                temp1->val+=1;
            }
           
        }


        return l1;

    }
};